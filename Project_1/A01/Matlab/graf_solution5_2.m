sol5 = load("data_solution5_high.txt");
% refazer quando o pc tiver mais tranquilo

n_sol5 = sol5(:,1);
t_sol5 = sol5(:,4);

semilogy(n_sol5,t_sol5, 'm-')
title("Solution 5 com um número elevado de road size")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;