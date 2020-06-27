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
        public void solve(InputReader in,PrintWriter out){
            int n = in.nextInt();
            int m = in.nextInt();
            int[] a = new int[n];
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
            }
            if(n > m){
                out.print(0);
                return;
            }
            long res = 1;
            for(int i = 0;i < n;++i){
                for(int j = 0;j < i;++j){
                    res = (res % (long)m* ((long)Math.abs(a[i] - a[j])) % (long)m) % (long)m;
                }
            }
            out.print(res);
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
