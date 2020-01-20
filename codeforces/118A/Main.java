
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        InputStream inputStream;
        OutputStream outputStream;
        if(System.getProperty("ONLINE_JUDGE") == null) {
            File input = new File("input.txt");
            File ouput = new File("output.txt");
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

        public void solve(int testNumber, InputReader in, PrintWriter out) {
 		String s;
		s = in.next();
		int n = s.length();
		char[] a = new char[n + 2];
		char[] b = {'U','u','E','e','O','o','A','a','Y','y','I','i'};
		s = s.toLowerCase();
		a = s.toCharArray();
		for(int i = 0;i < n;++i){
			boolean f = true;
			for(int j = 0;j < 12;++j){
				if(a[i] == b[j])
 					f = false;
			}
			if(!f)continue;
			out.print("." + a[i]);
		}        
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

