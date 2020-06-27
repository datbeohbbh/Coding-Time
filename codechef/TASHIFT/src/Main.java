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

        int n;
        String a,b,t;
        int[] zf;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            a = in.nextLine();
            b = in.nextLine();
            t = a + "#" + b + b;
            zf = new int[3 * n + 3];
            int l = -1,r = -1;
            for(int i = 1;i < t.length();++i){
                if(i <= r){
                    zf[i] = Math.min(zf[i - l],r - i + 1);
                }
                while(i + zf[i] < t.length() && t.charAt(zf[i]) == t.charAt(i + zf[i])){
                    ++zf[i];
                }
                if(i + zf[i] - 1 > r){
                    l = i;
                    r = i + zf[i] - 1;
                }
            }
            int lcp = 0,ans = 0;
            for(int i = n + 1;i < t.length();++i){
                if(zf[i] > lcp){
                    lcp = zf[i];
                    ans = i - n - 1;
                }
            }
            System.out.println(ans);
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
