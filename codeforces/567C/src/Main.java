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
        int n,k;
        long[] a;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            k = in.nextInt();
            a = new long[n + 1];
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
            }
            TreeMap <Long,Integer> tmap = new TreeMap <Long,Integer> ();
            TreeMap <Long,Integer> cnt = new TreeMap <Long,Integer> ();
            for(int i = 0;i < n;++i){
                if(!cnt.containsKey(a[i])){
                    cnt.put(a[i],1);
                } else {
                    int val = cnt.get(a[i]);
                    cnt.replace(a[i],val + 1);
                }
            }
            long ans = 0;
            for(int i = 0;i < n;++i){
                if(a[i] % k == 0){
                    int l = (tmap.containsKey(a[i] / k) ? tmap.get(a[i] / k) : 0);
                    int sub = (tmap.containsKey(a[i] * k) ? tmap.get(a[i] * k) : 0);
                    if(a[i] == a[i] * k){
                        ++sub;
                    }
                    int r = (cnt.containsKey(a[i] * k) ? cnt.get(a[i] * k) - sub : 0);
                    ans += (long)l * (long)r;
                }
                if(!tmap.containsKey(a[i])){
                    tmap.put(a[i],1);
                } else {
                    int val = tmap.get(a[i]);
                    tmap.replace(a[i],val + 1);
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
