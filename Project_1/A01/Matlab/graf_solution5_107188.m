sol5 = load("data_solution5_107188.txt");

n_sol5 = sol5(:,1);
t_sol5 = sol5(:,4);

semilogy(n_sol5,t_sol5, 'b-')
title("Solution 5")
xlabel("Posição final")
ylabel("Tempo (em segundos)")
grid on;