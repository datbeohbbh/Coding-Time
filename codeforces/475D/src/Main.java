import java.io.*;
import java.util.*;

public class Main {
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

        final static int lg = 20;
        int n;
        int[] a;
        int[] log;
        int[][] sp;
        TreeMap <Integer,Long> ans = new TreeMap<Integer,Long>();

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            a = new int[n + 2];
            sp = new int[n + 2][lg + 2];
            log = new int[n + 2];
            for(int i = 1; i <= n;++i){
                a[i] = in.nextInt();
                sp[i][0] = a[i];
            }
            for(int i = 2;i <= n;++i){
                log[i] = log[i >> 1] + 1;
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 1;i + (1 << j) - 1 <= n;++i){
                    sp[i][j] = gcd(sp[i][j - 1],sp[i + (1 << (j - 1))][j - 1]);
                }
            }
            for(int i = 1;i <= n;++i){
                for(int j = i;j <= n;++j){
                    int cur = getGcd(i,j);
                    int l = j,r = n;
                    int pos = j;
                    for(int mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                        if(getGcd(i,mid) == cur){
                            l = mid + 1;
                            pos = mid;
                        } else {
                            r = mid - 1;
                        }
                    }
                    long val = 0;
                    if(ans.containsKey(cur)){
                        val = ans.get(cur);
                        ans.remove(cur);
                    }
                    ans.put(cur,val + (pos - j + 1));
                    j = pos;
                }
            }
            int q;
            q = in.nextInt();
            for(;q > 0;--q){
                int x;
                x = in.nextInt();
                if(ans.containsKey(x)){
                    out.println(ans.get(x));
                } else {
                    out.println(0);
                }
            }
        }

        int getGcd(int l,int r){
            int x = log[r - l + 1];
            return gcd(sp[l][x],sp[r - (1 << x) + 1][x]);
        }

        int gcd(int u,int v){
            if(v == 0){
                return u;
            }
            return gcd(v,u % v);
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

        public long nextLong(){
            return Long.parseLong(next());
        }

        public  double nextDouble(){
            return Double.parseDouble(next());
        }

        public String nextLine(){
            String ret_str = "";
            try {
                ret_str = reader.readLine();
            } catch (IOException e){
                e.printStackTrace();
            }
            return ret_str;
        }
    }
}
