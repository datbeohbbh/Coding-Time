import javafx.scene.control.MultipleSelectionModel;

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

        int n,m;
        long[] l,r;
        Tuples[] a;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            a = new Tuples[m + 1];
            l = new long[n + 1];
            r = new long[n + 1];
            for(int i = 1;i <= n;++i){
                l[i] = in.nextLong();
                r[i] = in.nextLong();
            }
            for(int i = 1;i <= m;++i){
                a[i] = new Tuples(in.nextLong(),i);
            }
            Arrays.sort(a,1,m + 1,new Compare());
            int[] ans = new int[n + 1];
            int cur = 1;
            for(int i = 1;i < n;++i){
                long left = l[i + 1] - r[i];
                long right = r[i + 1] - l[i];
                boolean found = false;
                for(;cur <= m;++cur){
                    if(left <= a[cur].len && a[cur].len <= right){
                        ++cur;
                        found = true;
                        break;
                    }
                }
                if(found == false){
                    out.println("No");
                    return ;
                }
                ans[i] = a[cur - 1].index;
            }
            for(int i = 1;i < n;++i){
                out.print(ans[i] + " ");
            }
        }

        class Tuples{
            long len;
            int index;
            Tuples(long len,int index){
                this.len = len;
                this.index = index;
            }
        }

        class Compare implements Comparator <Tuples> {
            public int compare(Tuples x,Tuples y){
                int f = Long.compare(x.len,y.len);
                if(f == 0){
                    f = Integer.compare(x.index,y.index);
                }
                return  f;
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