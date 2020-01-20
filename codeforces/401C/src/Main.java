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
        public void solve(InputReader in,PrintWriter out){
            int n,m;
            n = in.nextInt();
            m = in.nextInt();
            if(m < n - 1){
                out.print(-1);
                return;
            }
            ArrayList <Integer> vec = new ArrayList <Integer>();
            for(int i = 0;i < n;++i){
                vec.add(0);
                vec.add(-1);
                vec.add(-1);
            }
            for(int mv = 1;mv <= 2;++mv) {
                for (int i = 0; i < vec.size(); i += 3) {
                    if (m > 0) {
                        vec.set(i + mv, 1);
                        --m;
                    }
                }
            }
            if(m > 2){
                out.print(-1);
            } else {
                for(int i = 0;i < m;++i){
                    out.print(1);
                }
                for(int i = 0;i < vec.size();++i){
                    if(vec.get(i) != -1){
                        out.print(vec.get(i));
                    }
                }
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
