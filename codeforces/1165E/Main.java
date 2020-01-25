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

        private final static long base = (long)998244353;
        int n;
        Long[] a;
        Long[] b;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            a = new Long[n];
            b = new Long[n];
            for(int i = 0;i < n;++i){
                a[i] = in.nextLong();
                a[i] = a[i] * (long)(i + 1) * (long)(n - i);
            }
            for(int i = 0;i < n;++i){
                b[i] = in.nextLong();
            }
            Arrays.sort(a);
            Arrays.sort(b,Collections.reverseOrder());
            long ans = 0;
            for(int i = 0;i < n;++i){
                ans = addMod(ans,mulMod(a[i],b[i]));
            }
            out.print(ans);
        }

        private long addMod(long x,long y){
            return ((x % base) + (y % base)) % base;
        }

        private long mulMod(long x,long y){
            return ((x % base) * (y % base)) % base;
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
