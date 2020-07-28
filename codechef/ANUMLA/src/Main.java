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
        int T = in.nextInt();
        for(int test = 1;test <= T;++test) {
            Task solver = new Task();
            solver.solve(in, out);
        }
        out.close();
    }

    static class Task{
        public void solve(InputReader in,PrintWriter out){
            int n = in.nextInt();
            int[] mask = new int[1 << n];
            for(int i = 0;i < (1 << n);++i){
                mask[i] = in.nextInt();
            }
            Arrays.sort(mask,0,(1 << n));
            for(int i = 0;i < n;++i){
                System.out.print(mask[1 << i] + " ");
            }
            System.out.print("\n");
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
