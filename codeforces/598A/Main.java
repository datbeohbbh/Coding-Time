
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
		int t;
		t = in.nextInt();
		for(int i = 1;i <= t;++i){
			long n;
			long sub = 0;
			n = in.nextLong();
			for(long pw = 1;pw <= n;pw<<=1){
				sub-=pw;
			}
			n = n*(n + 1)/2;
			out.println(n + 2*sub);
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

