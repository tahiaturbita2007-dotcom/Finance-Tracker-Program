#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct userlogin {
    char username[50];
    char password[20];
} login_info;

struct create_acc {
    char name[50];
    char email[200];
    char username[50];
    char password[20];
} user_input;

struct user_info {
    char profession[50];
    int total_budget;
    int saving_target;
    char source_of_income[50];
    char spheres[10][50];
    int number_of_spheres;
    int sphere_cost[10];
    char discuss_time[20];
} info;

struct daily_report {
    char expenditure_sector[10][50];
    int expenditure;
    int total_expense;
    float percentage;
    int number_of_coins;
    int number_of_sector;
    int count_coin;
} daily;


int login(void);
void create_acc(void);
void writeInfo(struct create_acc people);
void saveUserInfo(const char *username);
int loadUserInfo(const char *username);
void plan(void);
void queries(void);
void discuss(void);
void dashboard(void);

int main(void) {
    FILE *facc = fopen("acc.txt", "r");
    if (facc == NULL) {
        facc = fopen("acc.txt", "w");
        if (facc != NULL) {
            fprintf(facc, "%-15s %-30s %-15s %-15s\n", "Name", "Email", "Username", "Password");
            fclose(facc);
        }
    } else {
        fclose(facc);
    }

    int option;
    printf("<>>>>>>>>>>>>>>>>Welcome To Finance Tracker!<<<<<<<<<<<<<<<>\n\n");
    printf("Have you already created an account?---->Press 1 for login\n\nDon't have any account?---->Press 2 for registration\n\nExit---->Press 3");

    printf("\n\nPress here : ");
    if (scanf("%d", &option) != 1) return 0;

    if (option == 3) {
        printf("Exiting program....");
        exit(0);
    }

    switch (option) {
        case 1:
            if (login()) {
                dashboard();
            }
            break;

        case 2:
            create_acc();
            printf("\n**Let's come to queries**\n");
            queries();
            plan();
            int s;
            printf("\n\n\t\tShall we go to the dashboard now? Press 1---> ");
            scanf("%d", &s);
            if (s == 1) {
                dashboard();
            }
            break;

        default:
            printf("Report a problem\n");
            break;
    }

    return 0;
}


void saveUserInfo(const char *username) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_info.txt", username);

    FILE *fq = fopen(filename, "w");
    if (fq == NULL) {
        printf("Error opening user info file for writing!\n");
        return;
    }

    fprintf(fq, "%s\n", info.profession);
    fprintf(fq, "%d\n", info.total_budget);
    fprintf(fq, "%d\n", info.saving_target);
    fprintf(fq, "%s\n", info.source_of_income);
    fprintf(fq, "%s\n", info.discuss_time);
    fprintf(fq, "%d\n", info.number_of_spheres);

    for (int i = 0; i < info.number_of_spheres; i++) {
        fprintf(fq, "%s;%d\n", info.spheres[i], info.sphere_cost[i]);
    }

    fclose(fq);
}


int loadUserInfo(const char *username) {
    char filename[100];
    snprintf(filename, sizeof(filename), "%s_info.txt", username);

    FILE *fq = fopen(filename, "r");
    if (fq == NULL) {
        return 0; 
    }

    if (fscanf(fq, " %[^\n]", info.profession) != 1) { fclose(fq); return 0; }
    if (fscanf(fq, "%d", &info.total_budget) != 1) { fclose(fq); return 0; }
    if (fscanf(fq, "%d", &info.saving_target) != 1) { fclose(fq); return 0; }
    if (fscanf(fq, " %[^\n]", info.source_of_income) != 1) { fclose(fq); return 0; }
    if (fscanf(fq, " %[^\n]", info.discuss_time) != 1) { fclose(fq); return 0; }
    if (fscanf(fq, "%d", &info.number_of_spheres) != 1) { fclose(fq); return 0; }

    for (int i = 0; i < info.number_of_spheres; i++) {
        char line[100];
        if (fscanf(fq, " %[^\n]", line) == 1) {
            char *delim = strrchr(line, ';');
            if (delim != NULL) {
                *delim = '\0';
                strcpy(info.spheres[i], line);
                info.sphere_cost[i] = atoi(delim + 1);
            }
        }
    }

    fclose(fq);
    return 1;
}

void dashboard(void) {
    system("cls");
    int a;

    printf("\n\t\t******* Hey there, %s ! Let's keep that budget on track today!!! *******\n", user_input.name);
    printf("\n\n\t\t\t\t\t*****Your DASHBOARD*****\n\n");
    printf("Your monthly budget : %d\n", info.total_budget);
    printf("Your monthly savings' target : %d\n", info.saving_target);
    printf("Your daily budget : %d\n", info.total_budget / 30);
    printf("Your daily savings' goal : %d\n", info.saving_target / 30);
    printf("\n\nCheck out your daily budget plan! ----> 1\n");
    printf("Do not forget to discuss your daily expenses sharp at %s ----> 2\n", info.discuss_time[0] ? info.discuss_time : "N/A");
    printf("Exit----> 3\n");
    printf("Choose option on the basis of right cornered numbers : ");

    int opt;
    if (scanf("%d", &opt) != 1) return;
    switch (opt) {
        case 1:
            plan();
            break;
        case 2:
            discuss();
            break;
        case 3:
            printf("\n\nAll caught up! See you later...\n");
            exit(0);

        default:
            printf("\nSystem Error...\n");
            printf("Press 1 to choose again----->\n");
            printf("Press here---->");
            scanf("%d", &a);
            if (a == 1) {
                dashboard();
                return;
            }
    }
}

void discuss(void) {
    system("cls");
    int i;
    printf("\n\tHey!! Let's start today's discussion");
    printf("\nIn how many sectors did you spend today?:");
    scanf("%d", &daily.number_of_sector);

    int sum = 0;
    for (i = 0; i < daily.number_of_sector; i++) {
        printf("\nEnter the sector %d where you have spent today :", i + 1);
        scanf(" %[^\n]", daily.expenditure_sector[i]);
        printf("Enter the amount :");
        scanf("%d", &daily.expenditure);
        sum += daily.expenditure;
    }

    printf("\nToday's total spent money (Tk) : %d", sum);
    daily.total_expense = sum;

    int daily_limit = (info.total_budget - info.saving_target) / 30;
    if (daily_limit <= 0) daily_limit = 1; // Prevent division by zero

    int c = daily.total_expense - daily_limit;
    daily.percentage = (1.0 - ((float)c / daily_limit)) * 100.0;

    printf("\nYour Daily Budget Fulfillment Rate Based On Expenditure Limit is ---> %.2f%%", daily.percentage);

    if (daily.percentage < 0) {
        int r;
        printf("\nInvalid input! Expenditure limit went below 0%%. Please Enter your data correctly again!");
        printf("\nPress 1 to start discussion again--->");
        scanf("%d", &r);
        if (r == 1) {
            discuss();
            return;
        }
    }

    if (daily.percentage < 20) {
        daily.count_coin = 0;
    } else if (daily.percentage >= 20 && daily.percentage < 40) {
        daily.count_coin = 1;
    } else if (daily.percentage >= 40 && daily.percentage < 60) {
        daily.count_coin = 2;
    } else if (daily.percentage >= 60 && daily.percentage < 80) {
        daily.count_coin = 3;
    } else if (daily.percentage >= 80 && daily.percentage < 100) {
        daily.count_coin = 4;
    } else {
        daily.count_coin = 5;
    }

    if (daily.count_coin == 0) {
        printf("\nAlas! No coins earnt today.");
    } else {
        printf("\n\nCongratulations! You've claimed +%d coins today!", daily.count_coin);
        printf("\nGet your coins :");
        printf("[");
        for (int j = 1; j <= daily.count_coin; j++) {
            printf(" * ");
        }
        printf("]");
    }

    printf("\nPerformance Remark : ");
    if (daily.count_coin == 0) printf("\nAlas! You blew through your budget today; Time to recover!");
    if (daily.count_coin == 1) printf("\nPoor! You spent way more than planned; Careful tomorrow!");
    if (daily.count_coin == 2) printf("\nAverage! Not bad, but you went a bit off budget today.");
    if (daily.count_coin == 3) printf("\nGood effort! Pretty decent control, you kept things on track.");
    if (daily.count_coin == 4) printf("\nGreat job! Super smart choice and awesome money management.");
    if (daily.count_coin == 5) printf("\nExcellent! Spotless spending today, you nailed it!");

    int d;
    printf("\n\nBack to dashboard?\n");
    printf("Press 1--->");
    scanf("%d", &d);
    if (d == 1) {
        dashboard();
        return;
    }
}

int login(void) {
    while (1) {
        system("cls");
        printf("\n      ******Login****** \n");

        printf("\nUsername : ");
        scanf("%49s", login_info.username);
        printf("Password : ");
        scanf("%19s", login_info.password);

        FILE *facc = fopen("acc.txt", "r");
        if (facc == NULL) {
            printf("\nNo registered accounts found! Please register first.\n");
            system("pause");
            return 0;
        }

        char buffer[512];
        char f_name[50], f_email[200], f_user[50], f_pass[20];
        int found = 0;

        
        fgets(buffer, sizeof(buffer), facc);

        
        while (fscanf(facc, "%49s %199s %49s %19s", f_name, f_email, f_user, f_pass) == 4) {
            if (strcmp(login_info.username, f_user) == 0 && strcmp(login_info.password, f_pass) == 0) {
                strcpy(user_input.name, f_name);
                strcpy(user_input.email, f_email);
                strcpy(user_input.username, f_user);
                strcpy(user_input.password, f_pass);
                found = 1;
                break;
            }
        }
        fclose(facc);

        if (found) {
            printf("\nCongratulations! You have successfully logged in.\n");
            loadUserInfo(user_input.username); 
            system("pause");
            return 1;
        } else {
            int try_again;
            printf("\nInvalid log in! Press 1 to try again, or 0 to exit: ");
            scanf("%d", &try_again);
            if (try_again != 1) {
                exit(0);
            }
        }
    }
}

void create_acc(void) {
    system("cls");
    printf("     ******Create Your Account****** ");
    printf("\nEnter Your Name :");
    scanf("%49s", user_input.name);
    printf("\nEnter Your Email:");
    scanf("%199s", user_input.email);
    printf("\nCreate a Username:");
    scanf("%49s", user_input.username);
    printf("\nCreate Password:");
    scanf("%19s", user_input.password);

    writeInfo(user_input);

    system("cls");
    int p;
    printf("\n***Congratulations! Your account has been registered successfully! Press 1 to log in***\n");
    printf("\nPress Here :");
    scanf("%d", &p);
    if (p == 1) {
        login();
    }
}

void writeInfo(struct create_acc people) {
    FILE *facc = fopen("acc.txt", "a");
    if (facc == NULL) {
        printf("\nError opening database file for writing!\n");
        return;
    }
    fprintf(facc, "%-15s %-30s %-15s %-15s\n",
            people.name,
            people.email,
            people.username,
            people.password);
    fclose(facc);
}

void plan(void) {
    system("cls");

    int diff = info.total_budget - info.saving_target;
    printf("\n\t<==========>Here's your DAILY FINANCE PLAN<==========>\t\n");
    printf("Monthly Budget : %d\n", diff);
    printf("Daily Budget   : %d\n", diff / 30);

    printf("\n*******Each sphere and their respective expenses' plan(average per day cost plan)*******\n\n");
    printf("%-5s %-25s %-15s\n", "No.", "Sphere", "Expenditure");
    printf("--------------------------------------------------\n");

    for (int k = 0; k < info.number_of_spheres; k++) {
        printf("%-5d %-25s %-15d\n", k + 1, info.spheres[k], info.sphere_cost[k] / 30);
    }

    printf("\nIn terms of essential bills like electricity, gas and internet bill,\n");
    printf("please maintain economical mindset and spend money\n");
    printf("****according to the plan on daily basis****\n");
    printf("[Save money through wasting less on junk food and useless shoppings]\n");

    int b;
    printf("\n\nBack to dashboard?\n");
    printf("Press 1--->");
    scanf("%d", &b);
    if (b == 1) {
        dashboard();
        return;
    }
}

void queries(void) {
    system("cls");
    int option;
    printf("\n==========Help Us Build Your Plan!==========");

    printf("\n\nA.Choose your profession:");
    printf("\n\n1.Student\n2.Teacher\n3.Worker\n4.Business Person\n5.Doctor\n6.Engineer\n7.Corporate Officer\n8.Others");
    printf("\nChoose here according to the serial number : ");
    scanf("%d", &option);

    switch (option) {
        case 1: strcpy(info.profession, "Student"); break;
        case 2: strcpy(info.profession, "Teacher"); break;
        case 3: strcpy(info.profession, "Worker"); break;
        case 4: strcpy(info.profession, "Business Person"); break;
        case 5: strcpy(info.profession, "Doctor"); break;
        case 6: strcpy(info.profession, "Engineer"); break;
        case 7: strcpy(info.profession, "Corporate Officer"); break;
        case 8: strcpy(info.profession, "Others"); break;
        default:
            printf("Invalid option. Try again.\n");
            queries();
            return;
    }

    int source;
    printf("\nB.Enter your monthly budget :");
    scanf("%d", &info.total_budget);

    printf("\nC.Your savings goal :");
    scanf("%d", &info.saving_target);

    printf("\nD.Select your source of income ------>");
    printf("\n1.Pocket Money\n2.Salary\n3.Business Profit\n4.Part time job");
    printf("\nSelect Here :");
    scanf("%d", &source);

    switch (source) {
        case 1: strcpy(info.source_of_income, "Pocket Money"); break;
        case 2: strcpy(info.source_of_income, "Salary"); break;
        case 3: strcpy(info.source_of_income, "Business Profit"); break;
        case 4: strcpy(info.source_of_income, "Part time job"); break;
        default: strcpy(info.source_of_income, "Others"); break;
    }

    printf("\n=======E.Drop the spheres along with the range of expenses for each spheres========\n");
    printf("\t\tHow many sectors do you want to add? : ");
    scanf("%d", &info.number_of_spheres);

    for (int x = 0; x < info.number_of_spheres; x++) {
        printf("\nEnter the sector %d where you spend money: ", x + 1);
        scanf(" %[^\n]", info.spheres[x]);

        printf("Enter the expenditure: ");
        scanf("%d", &info.sphere_cost[x]);
    }

    printf("\nF.When do you prefer to discuss regular expenditure? (e.g. 10.00 am) : ");
    scanf(" %[^\n]", info.discuss_time);

    
    saveUserInfo(user_input.username);

    printf("\n\n***SUCCESS! YOUR DATA HAS BEEN SAVED SECURELY***\n");

    system("cls");
    int q;
    printf("\n***We are now ready to generate your customized finance plan!....***\n");
    printf("\nPress 1 to see the plan...\n");
    printf("Press Here :");
    scanf("%d", &q);
}