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

        final long base[] = {1000000007,1000000087};
        final long c[] = {29,31};
        long pow[][];
        Hash f,g;
        String s,t;
        int st,en;
        int latest = -1;

        public void solve(InputReader in,PrintWriter out){
            s = in.nextLine();
            t = in.nextLine();
            pow = new long[2][s.length() + 5];
            pow[0][0] = pow[1][0] = 1;
            for(int i = 0;i <= s.length();++i){
                for(int j = 0;j < 2;++j){
                    pow[j][i + 1] = (pow[j][i] * c[j]) % base[j];
                }
            }
            f = new Hash(s);
            g = new Hash(t);
            for(int l = 1,r = t.length(),mid = (l + r) >> 1;l <= r;mid = (l + r) >> 1){
                boolean found = compute(mid);
                if(found){
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if(latest == -1){
                out.println(0);
            } else {
                out.println(s.substring(st,en + 1));
                out.print(en - st + 1);
            }
        }

        boolean compute(int k){
            TreeMap < Long[],Integer > tm = new TreeMap<>((Long[] a,Long[] b) -> {
                int z = Long.compare(a[0],b[0]);
                return (z == 0 ? Long.compare(a[1],b[1]) : z);
            });
            for(int i = 0;i + k - 1 < t.length();++i){
                if(!tm.containsKey(g.getHash(i + 1,i + k))){
                    tm.put(g.getHash(i + 1,i + k),i + 1);
                }
            }
            int ret = Integer.MAX_VALUE;
            for(int i = 0;i + k - 1 < s.length();++i){
                if(tm.containsKey(f.getHash(i + 1,i + k))){
                    ret = Math.min(ret,tm.get(f.getHash(i + 1,i + k)));
                }
            }
            if(ret == Integer.MAX_VALUE){
                return false;
            }
            for(int i = 0;i + k - 1 < s.length();++i){
                if(tm.containsKey(f.getHash(i + 1,i + k))){
                    if(ret == tm.get(f.getHash(i + 1,i + k))){
                        if(latest == -1 || latest >= ret){
                            st = i;
                            en = i + k - 1;
                        }
                    }
                }
            }
            latest = ret;
            return true;
        }

        class Hash{

            private long h[][];
            private int len;

            Hash(String str){
                len = str.length();
                h = new long[2][len + 5];
                for(int i = 0;i < len;++i){
                    for(int j = 0;j < 2;++j){
                        h[j][i + 1] = (h[j][i] * c[j] + (long)(str.charAt(i) - 'a' + 1)) % base[j];
                    }
                }
            }

            long getHash(int l,int r,int j){
                return (h[j][r] - h[j][l - 1] * pow[j][r - l + 1] + base[j] * base[j]) % base[j];
            }

            Long[] getHash(int l,int r){
                Long res[] = new Long[2];
                res[0] = getHash(l,r,0);
                res[1] = getHash(l,r,1);
                return res;
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
