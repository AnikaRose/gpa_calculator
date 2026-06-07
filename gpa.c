#include <stdio.h>

#define PASS_GPA_THRESHOLD 2.00

float getGPA(float marks)
{
    if(marks >= 80) return 5.00;
    else if(marks >= 70) return 4.00;
    else if(marks >= 60) return 3.50;
    else if(marks >= 50) return 3.00;
    else if(marks >= 40) return 2.00;
    else if(marks >= 33) return 1.00;
    else return 0.00;
}

int main()
{
    int n, i;
    float marks, gpa;
    float totalGPA = 0;
    float optionalMarks, optionalGPA;
    int fail = 0;

    printf("=== SSC/HSC GPA Calculator (Bangladesh System) ===\n");

    printf("Enter number of compulsory subjects: ");
    scanf("%d", &n);

    // Compulsory subjects
    for(i = 1; i <= n; i++)
    {
        printf("Marks for Subject %d: ", i);
        scanf("%f", &marks);

        gpa = getGPA(marks);

        if(gpa == 0.00)
            fail = 1;

        totalGPA += gpa;
    }

    // Optional subject
    printf("Marks for Optional Subject: ");
    scanf("%f", &optionalMarks);

    optionalGPA = getGPA(optionalMarks);

    // Result calculation
    if(fail)
    {
        printf("\nResult: FAIL\n");
        printf("Final GPA: 0.00\n");
    }
    else
    {
        float bonus = 0.0;
        float finalGPA;

        // Optional subject bonus rule
        if(optionalGPA > PASS_GPA_THRESHOLD)
            bonus = optionalGPA - PASS_GPA_THRESHOLD;

        finalGPA = (totalGPA + bonus) / n;

        // GPA cannot exceed 5
        if(finalGPA > 5.00)
            finalGPA = 5.00;

        printf("\nResult: PASS\n");
        printf("Final GPA: %.2f\n", finalGPA);
    }

    return 0;
}