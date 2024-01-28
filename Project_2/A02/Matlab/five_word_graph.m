file_id = fopen("graph_fiveword_data.txt");
all_nodes = textscan(file_id, "%s %s");
node_A = all_nodes{:,1}';
node_B = all_nodes{:,2}';
G = graph(node_A,node_B);
plot(G)