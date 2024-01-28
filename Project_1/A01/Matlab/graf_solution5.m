sol5 = load("data_solution5.txt");

n_sol5 = sol5(:,1);
t_sol5 = sol5(:,4);

semilogy(n_sol5,t_sol5, 'm-')
title("Solution 5")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;

%% comparação com a solution 1

sol1 = load("data_solution1.txt");

n_sol1 = sol1(:,1);
t_sol1 = sol1(:,4);
figure(2)
semilogy(n_sol5,t_sol5, 'm-')
hold on;
semilogy(n_sol1, t_sol1, 'b-');
grid on;
legend('Solution 5', 'Solution 1')
title("Comparação entre Solution 1 e Solution 5")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
