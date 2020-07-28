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

        public static final int tx[] = {-1,0,1,0};
        public static final int ty[] = {0,1,0,-1};
        public static final char dir[] = {'U','R','D','L'};
        String[] s;
        int[] col;
        int[][] next;
        boolean[] white,black;
        int n,m,lg;
        int ans = 0,cntBlack = 0;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            while((1 << lg) <= n * m){
                ++lg;
            }
            s = new String[n + 2];
            col = new int[n * m + 2];
            next = new int[lg + 2][n * m + 2];
            for(int i = 1;i <= n;++i){
                String c;
                c = in.nextLine();
                for(int j = 1;j <= m;++j){
                    col[getIndex(i,j)] = (c.charAt(j - 1) == '0' ? 0 : 1);
                }
            }
            for(int i = 1;i <= n;++i){
                s[i] = in.nextLine();
            }
            for(int i = 1;i <= n;++i){
                for(int j = 1;j <= m;++j){
                    for(int k = 0;k < 4;++k){
                        if(s[i].charAt(j - 1) == dir[k]){
                            next[0][getIndex(i,j)] = getIndex(i + tx[k],j + ty[k]);
                        }
                    }
                }
            }
            for(int j = 1;j <= lg;++j){
                for(int i = 1;i <= n * m;++i){
                    next[j][i] = next[j - 1][next[j - 1][i]];
                }
            }
            white = new boolean[n * m + 2];
            black = new boolean[n * m + 2];
            Arrays.fill(white,false);
            Arrays.fill(black,false);
            for(int from = 1;from <= n * m;++from){
                int tot = n * m;
                int to = from;
                for(int deg = lg - 1;deg >= 0;--deg){
                    if(((tot >> deg) & 1) == 1){
                        to = next[deg][to];
                    }
                }
                if(col[from] == 0){
                    black[to] = true;
                } else {
                    white[to] = true;
                }
            }
            for(int u = 1;u <= n * m;++u){
                if(black[u]){
                    ++ans;
                    ++cntBlack;
                } else if(white[u]){
                    ++ans;
                }
            }
            out.println(ans + " " + cntBlack);
        }

        int getIndex(int i,int j){
            return (i - 1) * m + j;
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
