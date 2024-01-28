sol4 = load("data_solution4_107188.txt");

n_sol4 = sol4(:,1);
t_sol4 = sol4(:,4);

semilogy(n_sol4,t_sol4, 'b-')
title("Solution 4 - 107188")
xlabel("Posição final")
ylabel("Tempo (em segundos)")
grid on;