
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        InputStream inputStream;
        OutputStream outputStream;
        if(System.getProperty("ONLINE_JUDGE") == null) {
            File input = new File("inp.txt");
            File ouput = new File("out.txt");
            inputStream = new FileInputStream(input);
            outputStream = new FileOutputStream(ouput);
        }
        else {
            inputStream = System.in;
            outputStream = System.out;
        }
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        int nTest = 1;
        solver.solve(nTest, in, out);
        out.close();
    }

    static class Task {
	
	int n;
	int[] a = {0,1,2};
	long[] msk  = new long[10];
	long ans;
	
        public void solve(int testNumber, InputReader in, PrintWriter out) {
		n = in.nextInt();
		for(int i = 0;i < 8;++i)
			msk[i] = 1000000000;
		for(int i = 1;i <= n;++i){
			int c,mask = 0;
			String st;
			c = in.nextInt();
			st = in.next();
			char[] s = st.toCharArray();
			for(int j = 0;j < st.length();++j)
				mask|=(1<<a[s[j] - 'A']);
			msk[mask] = Math.min(msk[mask],(long)c);
		}      
		ans = msk[7];
		for(int i = 0;i < 8;++i)
		 if(msk[i] < 1000000000)
		  for(int j =0;j < 8;++j)
		   if(msk[j] < 1000000000){
		    if((i | j) == 7)
			ans = Math.min(ans,msk[i] + msk[j]);
		    for(int k = 0;k < 8;++k)
		     if(msk[k] < 1000000000)
		      if((i | j | k) == 7)
			ans = Math.min(ans,msk[i] + msk[j] + msk[k]);
		}

		if(ans == 1000000000)
			out.println(-1);
		else 
			out.println(ans); 
        }

    }
    
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}

