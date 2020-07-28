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

        public static final int maxVal = 200;
        int[][] cnt;
        int[] ar;
        ArrayList <Integer>[] pos;
        int n;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            ar = new int[n + 2];
            cnt = new int[maxVal + 2][n + 2];
            pos = new ArrayList[maxVal + 2];
            for(int val = 1;val <= maxVal;++val){
                pos[val] = new ArrayList <Integer>();
            }
            for(int i = 1;i <= n;++i){
                ar[i] = in.nextInt();
                pos[ar[i]].add(i);
            }
            int ans = 0;
            for(int val = 1;val <= maxVal;++val){
                ans = Math.max(ans,pos[val].size());
            }
            for(int val = 1;val <= maxVal;++val){
                for(int i = 1;i <= n;++i){
                    cnt[val][i] = cnt[val][i - 1] + (ar[i] == val ? 1 : 0);
                }
            }
            for(int a = 1;a <= maxVal;++a){
                if(pos[a].size() > 1){
                    for(int x = 1;x <= pos[a].size();++x){
                        if((x << 1) >= pos[a].size() + 1){
                            break;
                        }
                        int l = pos[a].get(x - 1);
                        int r = pos[a].get(pos[a].size() - x);
                        for(int b = 1;b <= maxVal;++b){
                            if(b != a) {
                                ans = Math.max(ans, (x << 1) + getSum(b,l, r));
                            }
                        }
                    }
                }
            }
            out.println(ans);
        }

        int getSum(int b,int l,int r){
            return cnt[b][r] - cnt[b][l - 1];
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
