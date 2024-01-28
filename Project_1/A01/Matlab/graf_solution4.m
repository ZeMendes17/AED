sol4 = load("data_solution4.txt");

n_sol4 = sol4(:,1);
t_sol4 = sol4(:,4);

semilogy(n_sol4,t_sol4, 'k-')
title("Solution 4")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;

%% comparação com a solution 1

sol1 = load("data_solution1.txt");

n_sol1 = sol1(:,1);
t_sol1 = sol1(:,4);
figure(2)
semilogy(n_sol4,t_sol4, 'k-')
hold on;
semilogy(n_sol1, t_sol1, 'b-');
grid on;
legend('Solution 4', 'Solution 1')
title("Comparação entre Solution 1 e Solution 4")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")