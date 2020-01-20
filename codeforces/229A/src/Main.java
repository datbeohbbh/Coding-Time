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
        String[] s;
        int[][] next_left;
        int[][] next_right;
        int[] left_most;
        int[] right_most;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            s = new String[n];
            for(int i = 0;i < n;++i){
                s[i] = in.nextLine();
            }
            next_left = new int[n][m];
            next_right = new int[n][m];
            left_most = new int[n];
            right_most = new int[n];
            Arrays.fill(left_most,-1);
            Arrays.fill(right_most,-1);
            for(int i = 0;i < n;++i){
                Arrays.fill(next_left[i],-1);
                Arrays.fill(next_right[i],-1);
                for(int j = 0;j < m;++j){
                    next_left[i][j] = (s[i].charAt(j) == '1' ? j : (j > 0 ? next_left[i][j - 1] : -1));
                    if(s[i].charAt(j) == '1' && left_most[i] == -1){
                        left_most[i] = j;
                    }
                }
                for(int j = m - 1;j >= 0;--j){
                    next_right[i][j] = (s[i].charAt(j) == '1' ? j : (j < m - 1 ?  next_right[i][j + 1] : -1));
                    if(s[i].charAt(j) == '1' && right_most[i] == -1){
                        right_most[i] = j;
                    }
                }
            }
            int ans = (int)(1e9);
            for(int j = 0;j < m;++j){
                int tmp = 0;
                for(int i = 0;i < n;++i){
                    int f = (int)(1e9);
                    if(left_most[i] != -1){
                        f = Math.min(f,left_most[i] + m - j);
                    }
                    if(right_most[i] != -1){
                        f = Math.min(f,m - right_most[i] + j);
                    }
                    if(next_right[i][j] != -1){
                        f = Math.min(f,next_right[i][j] - j);
                    }
                    if(next_left[i][j] != -1){
                        f = Math.min(f,j - next_left[i][j]);
                    }
                    if(f == (int)(1e9)){
                        tmp = (int)(1e9);
                    } else {
                        tmp += f;
                    }
                }
                ans = Math.min(ans,tmp);
            }
            out.print(ans == (int)1e9 ? -1 : ans);
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
