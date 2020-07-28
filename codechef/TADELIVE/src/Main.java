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

        int n,x,y;
        int []a;
        int []b;
        ArrayList <Integer> ord = new ArrayList<>();

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            x = in.nextInt();
            y = in.nextInt();
            a = new int[n];
            b = new int[n];
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
            }
            for(int i = 0;i < n;++i){
                b[i] = in.nextInt();
            }
            for(int i = 0;i < n;++i){
                ord.add(i);
            }
            Collections.sort(ord,new Cmp());
            int ans = 0;
            for(int i = 0;i < n;++i){
                int j = ord.get(i);
                if(a[j] > b[j]){
                    if(x > 0){
                        ans += a[j];
                        --x;
                    }  else {
                        ans += b[j];
                        --y;
                    }
                } else {
                    if(y > 0){
                        ans += b[j];
                        --y;
                    } else {
                        ans += a[j];
                        --x;
                    }
                }
            }
            out.print(ans);
        }

        class Cmp implements Comparator<Integer> {
            public int compare(Integer i, Integer j){
                int z = Integer.compare(Math.abs(a[i] - b[i]),Math.abs(a[j] - b[j]));
                return -z;
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
