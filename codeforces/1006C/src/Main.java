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
        int[] d;
        int n;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            d = new int[n + 1];
            for(int i = 0;i < n;++i){
                d[i] = in.nextInt();
            }
            TreeMap <Long,Integer> tmap = new TreeMap <Long,Integer> ();
            long suf_sum = 0;
            for(int i = n - 1;i >= 0;--i){
                suf_sum += (long)d[i];
                if(!tmap.containsKey(suf_sum)){
                    tmap.put(suf_sum,i);
                }
            }
            long pref_sum = 0;
            long ans = 0;
            for(int i = 0;i < n;++i){
                pref_sum += (long)d[i];
                if(tmap.containsKey(pref_sum)){
                    int r = tmap.get(pref_sum);
                    if(i < r){
                        ans = Math.max(ans,pref_sum);

                    }
                }
            }
            out.print(ans);
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
