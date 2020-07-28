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

        int[] a;
        int[][] f,g;
        int n;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            a = new int[n + 2];
            f = new int[n + 2][n + 2];
            g = new int[n + 2][n + 2];
            for(int i = 1;i <= n;++i){
                a[i] = in.nextInt();
            }
            for(int i = 1;i <= n;++i){
                f[i][i] = a[i];
            }
            for(int gap = 2;gap <= n;++gap){
                for(int l = 1,r = gap;r <= n;++l,++r){
                    f[l][r] = -1;
                    for(int mid = l;mid < r;++mid){
                        if(f[l][mid] != -1 && f[mid + 1][r] != -1){
                            if(f[l][mid] == f[mid + 1][r]){
                                f[l][r] = f[l][mid] + 1;
                                break;
                            }
                        }
                    }
                }
            }
            for(int i = 1;i <= n;++i){
                g[i][i] = 1;
            }
            for(int gap = 2;gap <= n;++gap){
                for(int l = 1,r = gap;r <= n;++l,++r){
                    if(f[l][r] != -1){
                        g[l][r] = 1;
                    } else {
                        g[l][r] = gap;
                        for(int mid = l;mid < r;++mid){
                            g[l][r] = Math.min(g[l][r],g[l][mid] + g[mid + 1][r]);
                        }
                    }
                }
            }
            out.print(g[1][n]);
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
