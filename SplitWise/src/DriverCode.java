import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

import Services.SplitWiseService;
import Utitlity.Round;

public class DriverCode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int inpsSize = 0;
        SplitWiseService splitWiseService = new SplitWiseService();
        while (inpsSize <= 10) {
            String type = sc.next();
            // System.out.println(owerdUsersList);
            switch (type) {
                case "EXPENSE":
                    String paidUser = sc.next();
                    double amount = sc.nextDouble();
                    int noOfOwedUsers = sc.nextInt();
                    HashMap<String, Double> owedUsers = new HashMap<>();
                    List<String> owerdUsersList = new ArrayList<>();
                    int i = 0;
                    while (i < noOfOwedUsers) {
                        owerdUsersList.add(sc.next());
                        i++;
                    }
                    String ExpenseType = sc.next();
                    // System.out.println(owerdUsersList);
                    i = 0;

                    switch (ExpenseType) {
                        case "EQUAL":
                            Double equalAmount = Round.round(amount / owerdUsersList.size());
                            owedUsers.put(owerdUsersList.get(0), equalAmount + (amount - equalAmount * owerdUsersList.size()));
                            i = 1;
                            while (i < noOfOwedUsers) {
                                owedUsers.put(owerdUsersList.get(i), equalAmount);
                                i++;
                            }
                            break;
                        case "PERCENT":
                            double totalPercentage = 100d;
                            while (i < noOfOwedUsers) {
                                double currPercentage = sc.nextDouble();
                                totalPercentage -= currPercentage;
                                owedUsers.put(owerdUsersList.get(i), amount * (currPercentage / 100));
                                i++;
                            }
                            if (totalPercentage != 0)
                                owedUsers = new HashMap<>();
                            break;

                        default:
                            while (i < noOfOwedUsers) {
                                owedUsers.put(owerdUsersList.get(i), sc.nextDouble());
                                i++;
                            }
                    }
                    splitWiseService.expense(paidUser, owedUsers);
                    break;

                case "SHOW":
                    String user = sc.next();
                    splitWiseService.show(user);
                    break;

                default:
                    splitWiseService.show(null);

            }
            inpsSize++;
        }
        sc.close();
    }
}
