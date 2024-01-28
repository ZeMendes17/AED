sol3 = load("data_solution3.txt");

n_sol3 = sol3(:,1);
t_sol3 = sol3(:,4);

plot(n_sol3,t_sol3, 'g-')
title("Solution 3")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;


%% comparação com a solution 1

sol1 = load("data_solution1.txt");

n_sol1 = sol1(:,1);
t_sol1 = sol1(:,4);
figure(2)
semilogy(n_sol3,t_sol3, 'g-')
hold on;
semilogy(n_sol1, t_sol1, 'b-');
grid on;
legend('Solution 3', 'Solution 1')
title("Comparação entre Solution 1 e Solution 3")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")