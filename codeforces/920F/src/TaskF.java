import java.io.*;
import java.util.*;

public class TaskF {
    public static void main(String[] args){
        InputStream  inputstream;
        OutputStream outputstream;
        inputstream = System.in;
        outputstream = System.out;
        InputReader in = new InputReader(inputstream);
        PrintWriter out = new PrintWriter(outputstream);
        Task solver = new Task();
        solver.solve(in,out);
        out.close();
    }

    static class Task{

        public static final int maxVal = (int)1e6;
        int n,m;
        int[] a;
        int[] g = new int[maxVal + 1];
        int[] cntD = new int[maxVal + 1];
        TreeSet <Integer> tset = new TreeSet <Integer> ();
        FenwickTree fen;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            a = new int[n + 1];
            for(int i = 1;i <= n;++i){
                a[i] = in.nextInt();
            }
            calc();
            fen = new FenwickTree();
            for(int i = 1;i <= n;++i){
                if(a[i] > 2){
                    tset.add(i);
                }
                fen.updateNode(i,a[i]);
            }
            for(;m > 0;--m){
                int op,l,r;
                op = in.nextInt();
                l = in.nextInt();
                r = in.nextInt();
                if(op == 1){
                    modify(l,r);
                } else {
                    out.println(fen.rsq(l,r));
                }
            }
        }

        private void modify(int l,int r){
            SortedSet <Integer> s = tset.subSet(l,r + 1);
            ArrayList <Integer> sub = new ArrayList <Integer> (s);
            for(Integer f : sub){
                int cur = (int)fen.rsq(f,f);
                a[f] = cntD[a[f]];
                fen.updateNode(f,a[f] - cur);
                if(a[f] <= 2){
                    tset.remove(f);
                }
            }
        }

        private void calc(){
            for(int i = 1;i <= maxVal;++i){
                g[i] = i;
            }
            for(int i = 2;i <= maxVal;++i){
                for(int j = (i << 1);j <= maxVal;j += i){
                    if(g[j] == j){
                        g[j] = i;
                    }
                }
            }
            cntD[1] = 1;
            for(int i = 2;i <= maxVal;++i){
                int tmp = i;
                cntD[i] = 1;
                for(int j = g[tmp];tmp > 1;j = g[tmp]){
                    int c = 0;
                    while(tmp % j == 0){
                        tmp /= j;
                        ++c;
                    }
                    cntD[i] *= (c + 1);
                }
            }
        }

        private class FenwickTree{
            long[] ft;
            FenwickTree(){
                ft = new long[n + 1];
                Arrays.fill(ft,0);
            }

            void updateNode(int node,int cur_val){
                for(;node <= n;node += node & (-node)){
                    ft[node] += (long)cur_val;
                }
            }

            long rsq(int node){
                long ret = 0;
                for(;node > 0;node -= node & (-node)){
                    ret += ft[node];
                }
                return ret;
            }

            long rsq(int l,int r){
                return rsq(r) - rsq(l - 1);
            }
        }
    }

    static class InputReader{
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream){
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next(){
            while(tokenizer == null || !tokenizer.hasMoreTokens()){
                try{
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e){
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt(){
            return Integer.parseInt(next());
        }
    }
}