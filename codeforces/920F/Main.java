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
        public static final int N = (int)(3e5 + 5);
        public static final int maxVal = (int)1e6;
        public static final int inf = (int)1e9;
        public static final int lg = 20;

        int n,m;
        int[] a;
        int[] g = new int[maxVal + 1];
        int[] cntD = new int[maxVal + 1];
        ArrayList <Divisor> d = new ArrayList <Divisor> ();
        SegmentTree segtree;
        SegmentTreeMinQuery segMin;
        SegmentTreeSumQuery segSum;

        public void solve(InputReader in,PrintWriter out){
            n = in.nextInt();
            m = in.nextInt();
            a = new int[n + 1];
            calc();
            for(int i = 0;i < n;++i){
                d.add(new Divisor());
            }
            for(int i = 0;i < n;++i){
                a[i] = in.nextInt();
                for(int j = 0;j <= lg;++j){
                    d.get(i).val[j] = (j - 1 >= 0 ? cntD[d.get(i).val[j - 1]] : a[i]);
                }
            }
            segtree= new SegmentTree();
            segMin = new SegmentTreeMinQuery();
            segSum = new SegmentTreeSumQuery();
            for(;m > 0;--m){
                int op,l,r;
                op = in.nextInt();
                l = in.nextInt() - 1;
                r = in.nextInt() - 1;
                if(op == 1){
                    int t = segMin.getRmq(l,r,0,n - 1,1);
                    if(t < lg){
                        modify(l,r);
                        segMin.updateMin(l,r,0,n - 1,1);
                    }
                } else {
                    out.println(segSum.getRsq(l,r,0,n - 1,1));
                }
            }
        }

        private void modify(int l,int r){
            for(int j = l;j <= r;++j){
                int h = segMin.getRmq(j,j,0,n - 1,1);
                if(h < lg){
                    segSum.updateSum(j,d.get(j).val[h + 1],0,n - 1,1);
                }
            }
        }

        private void calc(){
            for(int i = 1;i <= maxVal;++i){
                g[i] = i;
            }
            for(int i = 2;i <= maxVal;++i){
                for(int j = (i << 1);j <= maxVal;j += i){
                    if(g[j] == j){
                        g[j] = i;
                    }
                }
            }
            cntD[1] = 1;
            for(int i = 2;i <= maxVal;++i){
                int tmp = i;
                cntD[i] = 1;
                for(int j = g[tmp];tmp > 1;j = g[tmp]){
                    int c = 0;
                    while(tmp % j == 0){
                        tmp /= j;
                        ++c;
                    }
                    cntD[i] *= (c + 1);
                }
            }
        }

        private class Divisor{
            int[] val;
            public Divisor(){
                val = new int[lg + 1];
                Arrays.fill(val,0);
            }
        }

        private class SegmentTree{

            public class Node {
                int minVal;
                long sumVal;
                public Node(int minVal,long sumVal){
                    this.minVal = minVal;
                    this.sumVal = sumVal;
                }
            }

            long[] lazy;
            Node[] tree;

            public SegmentTree(){
                lazy = new long[(N + 1) << 1];
                tree = new Node[(N + 1) << 1];
                Arrays.fill(lazy,(long)0);
                Arrays.fill(tree,new Node(inf,0));
                buildTree(0,n - 1,1);
            }

            public Node combineNode(Node l,Node r){
                return new Node(Math.min(l.minVal,r.minVal),l.sumVal + r.sumVal);
            }

            public void buildTree(int l,int r,int node){
                if(l > r)return;
                if(l == r){
                    tree[node] = new Node(0,a[l]);
                    return ;
                }
                int mid = (l + r) >> 1;
                buildTree(l,mid,node<<1);
                buildTree(mid + 1,r,node<<1|1);
                tree[node] = combineNode(tree[node<<1],tree[node<<1|1]);
            }
        }

        public class SegmentTreeMinQuery extends SegmentTree{
            void down(int l,int r,int node){
                if(lazy[node] == 0){
                    return ;
                }
                tree[node].minVal += lazy[node];
                if(l != r){
                    lazy[node<<1] += lazy[node];
                    lazy[node<<1|1] += lazy[node];
                }
                lazy[node] = 0;
            }

            void updateMin(int tl,int tr,int l,int r,int node){
                down(l,r,node);
                if(l > r || r < tl || l > tr)return;
                if(tl <= l && r <= tr){
                    tree[node].minVal += 1;
                    if(l != r){
                        lazy[node<<1] += 1;
                        lazy[node<<1|1] += 1;
                    }
                    return ;
                }
                int mid = (l + r) >> 1;
                updateMin(tl,tr,l,mid,node<<1);
                updateMin(tl,tr,mid + 1,r,node<<1|1);
                tree[node].minVal = Math.min(tree[node<<1].minVal,tree[node<<1|1].minVal);
            }

            int getRmq(int tl,int tr,int l,int r,int node){
                down(l,r,node);
                if(l > r || r < tl || l > tr){
                    return inf;
                }
                if(tl <= l && r <= tr){
                    return tree[node].minVal;
                }
                int mid = (l + r) >> 1;
                return Math.min(getRmq(tl,tr,l,mid,node<<1),getRmq(tl,tr,mid + 1,r,node<<1|1));
            }
        }

        public class SegmentTreeSumQuery extends SegmentTree{
            void updateSum(int pos,int cur_val,int l,int r,int node){
                if(l > r || r < pos || l > pos){
                    return;
                }
                if(l == r){
                    tree[node].sumVal = (long)cur_val;
                    return;
                }
                int mid = (l + r) >> 1;
                if(pos <= mid){
                    updateSum(pos,cur_val,l,mid,node<<1);
                } else {
                    updateSum(pos,cur_val,mid + 1,r,node<<1|1);
                }
                tree[node].sumVal = tree[node<<1].sumVal + tree[node<<1|1].sumVal;
            }
            long getRsq(int tl,int tr,int l,int r,int node){
                if(l > r || r < tl || l > tr){
                    return 0;
                }
                if(tl <= l && r <= tr){
                    return tree[node].sumVal;
                }
                int mid = (l + r) >> 1;
                return getRsq(tl,tr,l,mid,node<<1) + getRsq(tl,tr,mid + 1,r,node<<1|1);
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
