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

        int[] cnt;
        int n,k;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            k = in.nextInt();
            cnt = new int[k];
            for(int i = 0;i < n;++i){
                int t;
                t = in.nextInt();
                ++cnt[t - 1];
            }
            Arrays.sort(cnt);
            long ans = (long) 1e18;
            for(int i = 0;i < (k >> 1);++i){
                if((i << 1) + 1 <= k){
                    ans = Math.min(ans,calc(cnt[i] + cnt[k - i - 1]));
                }
            }
            ans = Math.min(ans,calc(cnt[k - 1]));
            out.print(ans);
        }

        long calc(long val){
            int l = 0,r = k - 1;
            int rides = 0;
            while(l <= r){
                if(val < cnt[r]){
                    return (long) 1e18;
                }
                if(val >= cnt[l] + cnt[r] - (l == r ? 1 : 0) * cnt[l]){
                    ++rides;
                    ++l;
                    --r;
                } else {
                    ++rides;
                    --r;
                }
            }
            return rides * val;
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
