//package com.efimchick.ifmo.io.filetree;

import java.io.FilenameFilter;
import java.nio.file.Path;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.io.File;

public class FileTreeImpl implements FileTree {

    private Optional <String> ans;
    private String graph_symbols[] = {"├","─","└","│",""};

    public Optional<String> tree(Path path){
        if(path == null){
            return Optional.empty();
        }
        File cur = new File(path.toString());
        if(!cur.exists()){
            return Optional.empty();
        }
        if(cur.isFile()){
            return ans.of(Stream.of(cur.getName(),Long.toString(cur.length()),"bytes")
                         .collect(Collectors.joining(" ")));
        } else {
            Tree tree = new Tree(path);
            List <String> li = tree.getTree();
            return ans.of(li.stream().collect(Collectors.joining("\n")));
        }
    }

    private class Tree{

        Path path;
        ArrayList <Vertex> gr = new ArrayList<>();
        ArrayList < ArrayList < String > > board = new ArrayList<>();
        int[] start_pos;
        int[] pos_child;
        int[] r;

        Tree(Path path){
            this.path = path;
            ArrayList< ArrayList <Vertex> > adj = new ArrayList<>();
        }

        class Vertex{
            int dad,size_t,index,is_file;
            String name;
            ArrayList <Integer> adj;
            Vertex(int index,int size_t,int dad,String name){
                this.index = index;
                this.size_t = size_t;
                this.dad = dad;
                this.name = name;
                this.is_file = 0;
                adj = new ArrayList<>();
            }
        }

        List <String> getTree(){
            gr.add(new Vertex(0,0,0,new File(path.toString()).getName()));
            buildTree(path,0);
            pos_child = new int[gr.size()];
            for(int i = 0;i < gr.size();++i){
                Collections.sort(gr.get(i).adj,(Integer u,Integer v) -> {
                    int z = Integer.compare(gr.get(u).is_file,gr.get(v).is_file);
                    if(z == 0){
                        z = gr.get(u).name.toLowerCase().compareTo(gr.get(v).name.toLowerCase());
                    }
                    return z;
                });
                for(int j = 0;j < gr.get(i).adj.size();++j){
                    pos_child[gr.get(i).adj.get(j)] = j;
                }
            }
            start_pos = new int[gr.size()];
            r = new int[gr.size()];
            dfs(0);
            formatTable(0);
            List <String> ret = board.stream()
                                     .map(iter -> iter.stream().collect(Collectors.joining("")))
                                     .collect(Collectors.toList());
            return ret;
        }

        void addToBoard(int end_pos,int i,int j){
            board.get(end_pos).add(graph_symbols[i] + graph_symbols[j] + " ");
        }

        void dfs(int u){
            r[u] = board.size();
            board.add(new ArrayList<>());
            int par = gr.get(u).dad;
            int end_pos = board.size() - 1;
            for(int i = 0;i < start_pos[par];++i){
                board.get(end_pos).add(" ");
            }
            if(u != par){
                if(gr.get(par).adj.size() == 1){
                    addToBoard(end_pos,2,1);
                } else {
                    if(pos_child[u] == 0){
                        addToBoard(end_pos,0,1);
                    } else if(pos_child[u] == gr.get(par).adj.size() - 1){
                        addToBoard(end_pos,2,1);
                    } else {
                        addToBoard(end_pos,0,1);
                    }
                }
                start_pos[u] = start_pos[par] + 3;
            }
            board.get(end_pos).add(Stream.of(gr.get(u).name,Integer.toString(gr.get(u).size_t),"bytes")
                                  .collect(Collectors.joining(" ")));
            for(int v : gr.get(u).adj) {
                dfs(v);
            }
        }

        void formatTable(int u){
            for(int i = 1;i < gr.get(u).adj.size();++i){
                int x = gr.get(u).adj.get(i - 1);
                int y = gr.get(u).adj.get(i);
                if(r[x] <= r[y] - 2){
                    for(int j = r[x] + 1;j < r[y];++j){
                        int p = start_pos[x] - 3;
                        if(p >= 0) {
                            board.get(j).set(p, graph_symbols[3]);
                        }
                    }
                }
            }
            for(int v : gr.get(u).adj) {
                formatTable(v);
            }
        }

        void buildTree(Path u,int par){
            File cur = new File(u.toString());
            if(cur.isFile()){
                gr.get(par).size_t = (int)cur.length();
                gr.get(par).is_file = 1;
                return;
            }
            FilenameFilter f = new FilenameFilter() {
                @Override
                public boolean accept(File file, String s) {
                    return file.exists();
                }
            };
            File[] ff = cur.listFiles(f);
            for(File element : ff){
                int v = gr.size();
                gr.add(new Vertex(v,0,par,element.getName()));
                gr.get(par).adj.add(v);
                gr.get(v).dad = par;
                buildTree(element.toPath(),v);
                gr.get(par).size_t += gr.get(v).size_t;
            }
        }
    }
}
