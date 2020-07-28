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
            int n;
            n = in.nextInt();
            int[] a = new int[n + 1];
            int[] b = new int[n + 1];
            TreeMap <Integer,Integer> tmap = new TreeMap <Integer,Integer> ();
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
            }
            for(int i = 0;i < n;++i){
                b[i] = in.nextInt();
                if(!tmap.containsKey(b[i])){
                    tmap.put(b[i],1);
                } else {
                    tmap.replace(b[i],tmap.get(b[i]) + 1);
                }
            }
            for(int i = 0;i < n;++i){
                if(tmap.ceilingKey(n - a[i]) != null){
                    Map.Entry <Integer,Integer> t = tmap.ceilingEntry(n - a[i]);
                    out.print((a[i] + t.getKey()) % n + " ");
                    if(t.getValue() == 1){
                        tmap.remove(t.getKey());
                    } else {
                        tmap.replace(t.getKey(),t.getValue() - 1);
                    }
                } else {
                    out.print((a[i] + tmap.firstKey()) % n + " ");
                    if(tmap.get(tmap.firstKey()) == 1){
                        tmap.remove(tmap.firstKey());
                    } else {
                        tmap.replace(tmap.firstKey(),tmap.get(tmap.firstKey()) - 1);
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
