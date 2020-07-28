import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args){
        InputStream  inputstream;
        OutputStream outputstream;
        inputstream = System.in;
        outputstream = System.out;
        InputReader in = new InputReader(inputstream);
        PrintWriter out = new PrintWriter(outputstream);
        int test;
        test = in.nextInt();
        while(test-- > 0) {
            Task solver = new Task();
            solver.solve(in, out);
        }
        out.close();
    }

    static class Task{
        public void solve(InputReader in,PrintWriter out){
            int n,m,a,b;
            n = in.nextInt();
            m = in.nextInt();
            a = in.nextInt();
            b = in.nextInt();
            if(a * n != b * m){
                out.println("NO");
            } else {
                int shift = 0;
                for(int i = 1;i < m;++i){
                    if((i * n) % m == 0){
                        shift = i;
                        break;
                    }
                }
                ArrayList <String> [] ans = new ArrayList[n];
                for(int i = 0;i < n;++i){
                    ans[i] = new ArrayList<>();
                    for(int j = 0;j < m;++j){
                        ans[i].add("0");
                    }
                }
                for(int t = 0,i = 0;i < n;++i,t += shift){
                    for(int j = 0;j < a;++j){
                        ans[i].set((j + t) % m,"1");
                    }
                }
                out.println("YES");
                String res = Arrays.stream(ans)
                                   .map(i -> i.stream().collect(Collectors.joining("")))
                                   .collect(Collectors.joining("\n"));
                out.println(res);
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
