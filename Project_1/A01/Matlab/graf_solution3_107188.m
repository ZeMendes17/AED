sol3 = load("data_solution3_107188.txt");

n_sol3 = sol3(:,1);
t_sol3 = sol3(:,4);

plot(n_sol3,t_sol3, 'b-')
title("Solution 3 - 107188")
xlabel("Posição final")
ylabel("Tempo (em segundos)")
grid on;