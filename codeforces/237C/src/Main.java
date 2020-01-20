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

        private static final int N = 1000000;
        int a,b,k;
        int[] isPrime;

        public void solve(InputReader in,PrintWriter out){
            a = in.nextInt();
            b = in.nextInt();
            k = in.nextInt();
            sievePrime(N);
            int ans = -1;
            for(int l = 1,r = b - a + 1,mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                if(chk(mid)){
                    ans = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            out.print(ans);
        }

        boolean chk(int w){
            for(int x = a;x <= b - w + 1;++x){
                if(isPrime[x + w - 1] - isPrime[x - 1] < k){
                    return false;
                }
            }
            return true;
        }

        void sievePrime(int maxN){
            isPrime = new int[maxN + 2];
            Arrays.fill(isPrime,1);
            isPrime[0] = isPrime[1] = 0;
            for(int i = 2;i <= maxN;++i){
                if(isPrime[i] == 1) {
                    for (int j = (i << 1); j <= maxN; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
            for(int i = 2;i <= maxN;++i){
                isPrime[i] += isPrime[i - 1];
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
