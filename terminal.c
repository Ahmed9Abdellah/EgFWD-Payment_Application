#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"terminal.h"
#include"../Card/card.h"
#include"../STD_TYPES.h"


void getTransactionDateTest(void)
{
	uint8_t c;
	uint8_t Trans_Date[11];
	uint8_t Tester_name[11];
	printf("Tester Name :");
	scanf("%s", &Tester_name);
	printf("Function Name : getTransactionDate \n");
	printf("Please enter Transaction Date :");
	scanf("%s", &Trans_Date);
	printf("Please enter case number \n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("Test Case 1 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : TERMINAL_OK \n");
		if (strlen(Trans_Date) == 10) {
			printf("Actual Result : TERMINAL_OK ");
		}
		break;
	case 2:
		printf("Test Case 2 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : WRONG_DATE \n");
		if (strlen(Trans_Date) != 10) {
			printf("Actual Result : WRONG_DATE");
			break;
	case 3:
		printf("Test Case 3 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : WRONG_DATE \n");
		if ((Trans_Date[0] == '3') && Trans_Date[1] > '1'
			|| (Trans_Date[0] >= '4')
			)
		
		{
			printf("Actual Result : WRONG_DATE");
			break;
		}
	case 4:
		printf("Test Case 4 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : WRONG_DATE \n");
		if (Trans_Date[3] >= '2' )
		{
			printf("Actual Result : WRONG_DATE");
			break;
		}
	case 5:
		printf("Test Case 5 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : WRONG_DATE \n");
		if ((Trans_Date[0] < '1') && (Trans_Date[1] < '1') || (Trans_Date[3] < '1') && (Trans_Date[4] < '1')
			|| (Trans_Date[6] < '1') && (Trans_Date[7] < '1') || (Trans_Date[8]<'1') && (Trans_Date[9]<'1')){
			printf("Actual Result : WRONG_DATE");
			break;
		}
	case 6:
		printf("Test Case 6 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Expected Result : WRONG_DATE \n");
		for (uint16_t i = 0; Trans_Date[i] != '\0'; i++) {
			if ((Trans_Date[i] >= 'a' && Trans_Date[i] <= 'z') || (Trans_Date[i] >= 'A' && Trans_Date[i] <= 'Z')) {

			printf("Actual Result : WRONG_DATE");
			break;
			}
			break;
		}

		}
	}
}
void isCardExpiredTest(void)
{

	uint8_t c;
	uint8_t arr_year_TRANS[2];
	uint8_t arr_month_TRANS[2];
	uint8_t arr_year_EXP[2];
	uint8_t arr_month_EXP[2];
	uint8_t Expire_Date[6];
	uint8_t Trans_Date[11];
	uint8_t Tester_name[11];

	printf("Tester Name :");
	scanf("%s", &Tester_name);
	printf("Function Name : isCardExpired \n");
	printf("Please enter Transaction Date :");
	scanf("%s", &Trans_Date);
	printf("Please enter Expiration Date :");
	scanf("%s", &Expire_Date);
	printf("Please enter case number \n");
	
	scanf("%d", &c);

	switch (c)
	{
	case 1:
		printf("Test Case 1 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : TERMINAL_OK \n");
		for (uint8_t i = 0; i < 11; i++) {
			if (i == 0)
			{
				arr_month_EXP[0] = Expire_Date[0];

			}
			if (i == 1)
			{
				arr_month_EXP[1] = Expire_Date[1];
			}
			if (i == 2)
			{
				continue;
			}
			if (i == 3)
			{
				arr_year_EXP[0] = Expire_Date[3];
				arr_month_TRANS[0] = Trans_Date[3];
			}
			if (i == 4)
			{
				arr_year_EXP[1] = Expire_Date[4];
				arr_month_TRANS[1] = Trans_Date[4];
			}
			if ((i == 5) || (i == 6) || (i == 7))
			{
				continue;
			}
			if (i == 8)
			{
				arr_year_TRANS[0] = Trans_Date[8];
			}
			if (i == 9)
			{
				arr_year_TRANS[1] = Trans_Date[9];
			}


		}

		//2nd case EX : Expireation Date : 05/26
		// Transaction Date  25/06/2025
	//1st case EX: Expireation Date : 10/25
		// Transaction Date  25/06/2025

		if (((arr_month_EXP[0] > arr_month_TRANS[0]) && (arr_month_EXP[1] < arr_month_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] > arr_month_TRANS[1]))
			|| ((arr_year_EXP[0] >= arr_year_TRANS[0]) && (arr_year_EXP[1] > arr_year_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] < arr_month_TRANS[1]))
			&& ((arr_year_EXP[0] >= arr_year_TRANS[0]) && (arr_year_EXP[1] > arr_year_TRANS[1])))
		{
			printf("Actual Result : TERMINAL_OK");

		}

		break;
	case 2:
		printf("Test Case 2 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : EXPIRED_CARD \n");
		for (uint8_t i = 0; i < 11; i++) {
			if (i == 0)
			{
				arr_month_EXP[0] = Expire_Date[0];

			}
			if (i == 1)
			{
				arr_month_EXP[1] = Expire_Date[1];
			}
			if (i == 2)
			{
				continue;
			}
			if (i == 3)
			{
				arr_year_EXP[0] = Expire_Date[3];
				arr_month_TRANS[0] = Trans_Date[3];
			}
			if (i == 4)
			{
				arr_year_EXP[1] = Expire_Date[4];
				arr_month_TRANS[1] = Trans_Date[4];
			}
			if ((i == 5) || (i == 6) || (i == 7))
			{
				continue;
			}
			if (i == 8)
			{
				arr_year_TRANS[0] = Trans_Date[8];
			}
			if (i == 9)
			{
				arr_year_TRANS[1] = Trans_Date[9];
			}

		}

		//# Case 1
		//  EX: 05/21
		//EX:  25/06/2022

		//# Case 2
		//  EX: 10/21
		//EX:  25/06/2022
		if (((arr_month_EXP[0] < arr_month_TRANS[0]) && (arr_month_EXP[1] > arr_month_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] < arr_month_TRANS[1]))
			|| ((arr_year_EXP[0] <= arr_year_TRANS[0]) && (arr_year_EXP[1] < arr_year_TRANS[1])))
		{
			printf("Actual Result : EXPIRED_CARD");
		}
		break;

	case 3:
		printf("Test Case 3 \n");
		printf("Input Data : %s \n", Trans_Date);
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : WRONG FORMAT \n");
		if ((strlen(Expire_Date) != 5) || (strlen(Trans_Date) != 10))
		{
			printf("Actual Result : WRONG FORMAT");
			exit(0);

		}
		break;
	}
}

	void getTransactionAmountTest(void)
	{
		uint8_t c;
		uint8_t Tester_name[11];
		float32_t TransAmount;
		printf("Tester Name :");
		scanf("%s",&Tester_name);
		printf("Function Name : getTransactionAmount \n");
		printf("Please enter Transaction Amount :");
		scanf("%f",&TransAmount);
		printf("Please enter case number \n");
		scanf("%d",&c);
		switch (c)
		{
		case 1:
			printf("Test Case 1 \n");
			printf("Input Data : %.2f \n",TransAmount);
			printf("Expected Result : TERMINAL_OK \n");
			if (TransAmount != 0) {
				printf("Actual Result : TERMINAL_OK ");
			}
			break;
		case 2:
			printf("Test Case 2 \n");
			printf("Input Data : %.2f \n",TransAmount);
			printf("Expected Result : INVALID_AMOUNT \n");
			if (TransAmount==0) {
				printf("Actual Result : INVALID_AMOUNT");
				break;
			}
		}
	}
	void isBelowMaxAmountTest(void)
	{
		uint8_t c;
		uint8_t Tester_name[11];
		float32_t TransAmount;
		float32_t Max_Amount;
		printf("Tester Name :");
		scanf("%s", &Tester_name);
		printf("Function Name : isBelowMaxAmount \n");
		printf("Please enter Transaction Amount :");
		scanf("%f", &TransAmount);
		printf("Please enter Max Amount : ");
		scanf("%f", &Max_Amount);
		printf("Please enter case number \n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("Test Case 1 \n");
			printf("Input Data : %.2f \n", TransAmount);
			printf("Input Data : %.2f \n", Max_Amount);
			printf("Expected Result : TERMINAL_OK \n");
			if (TransAmount < Max_Amount) {
				printf("Actual Result : TERMINAL_OK ");
			}
			break;
		case 2:
			printf("Test Case 2 \n");
			printf("Input Data : %.2f \n", TransAmount);
			printf("Input Data : %.2f \n", Max_Amount);
			printf("Expected Result : EXCEED_MAX_AMOUNT \n"); 
			if (TransAmount > Max_Amount) {
				printf("Actual Result : EXCEED_MAX_AMOUNT");
				break;
			}
		}
	
	}

	void setMaxAmountTest(void)
	{
		uint8_t c;
		uint8_t Tester_name[11];
		float32_t TransAmount;
		float32_t Max_Amount;
		printf("Tester Name :");
		scanf("%s", &Tester_name);
		printf("Function Name : setMaxAmount \n");
		printf("Please enter Max Transaction Amount :");
		scanf("%f", &Max_Amount);
		printf("Please enter case number \n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			printf("Test Case 1 \n");
			printf("Input Data : %.2f \n", Max_Amount);
			printf("Expected Result : TERMINAL_OK \n");
			if ( Max_Amount>0) {
				printf("Actual Result : TERMINAL_OK ");
			}
			break;
		case 2:
			printf("Test Case 2 \n");
			printf("Input Data : %.2f \n", Max_Amount);
			printf("Expected Result : INVALID_MAX_AMOUNT \n");
			if ( Max_Amount<=0) {
				printf("Actual Result : INVALID_MAX_AMOUNT");
				break;
			}
		}

	}



	EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
	{

		printf("enter Transaction Date \n");
		gets(termData->transactionDate);
		uint16_t len;
		len = strlen(termData->transactionDate);
		if (len != 10)
		{
			return WRONG_DATE;
		}
		for (uint16_t i = 0; termData->transactionDate[i] != '\0'; i++) {
			if ((termData->transactionDate[i] >= 'a' && termData->transactionDate[i] <= 'z') || (termData->transactionDate[i] >= 'A' && termData->transactionDate[i] <= 'Z'))

			{
				return WRONG_DATE;

			}
		}
		if ((termData->transactionDate[0] == '3') && (termData->transactionDate[1] > '1')  
			|| (termData->transactionDate[0] >= '4'))
			
		{
			return WRONG_DATE;
		}
		else if ((termData->transactionDate[0] < '1') && (termData->transactionDate[1] < '1') || (termData->transactionDate[3] < '1') && (termData->transactionDate < '1')
			|| (termData->transactionDate[6] < '1') && (termData->transactionDate[7] < '1')|| (termData->transactionDate[8] < '1') && (termData->transactionDate[9] < '1'))
	{
		return WRONG_DATE;
	}
		else if ((termData->transactionDate[3] >='2'))
		{
			return WRONG_DATE;
		}
		else {

		return TERMINAL_OK;
		}
}


	EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
	{
		uint8_t arr_year_TRANS[2];
		uint8_t arr_month_TRANS[2];
		uint8_t arr_year_EXP[2];
		uint8_t arr_month_EXP[2];
		uint8_t cardExpirationDate[6];  // EX: 05/25
		uint8_t transactionDate[11]; //EX:  25/06/2022
		printf("Please enter Expiration Date : ");
		gets(cardExpirationDate);
		printf("Please enter Transction Date : ");
		gets(transactionDate);
		if ((strlen(cardExpirationDate) != 5) || (strlen(transactionDate) != 10))
		{
			printf("WRONG FORMAT");
			exit(0);

		}
		else {


			for (uint8_t i = 0; i < 11; i++) {
				if (i == 0)
				{
					arr_month_EXP[0] = cardExpirationDate[0];

				}
				if (i == 1)
				{
					arr_month_EXP[1] = cardExpirationDate[1];
				}
				if (i == 2)
				{
					continue;
				}
				if (i == 3)
				{
					arr_year_EXP[0] = cardExpirationDate[3];
					arr_month_TRANS[0] = transactionDate[3];
				}
				if (i == 4)
				{
					arr_year_EXP[1] = cardExpirationDate[4];
					arr_month_TRANS[1] = transactionDate[4];
				}
				if ((i == 5) || (i == 6) || (i == 7))
				{
					continue;
				}
				if (i == 8)
				{
					arr_year_TRANS[0] = transactionDate[8];
				}
				if (i == 9)
				{
					arr_year_TRANS[1] = transactionDate[9];
				}

			}
		}
	if (((arr_month_EXP[0] < arr_month_TRANS[0]) && (arr_month_EXP[1] > arr_month_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] <= arr_month_TRANS[1]))
		&& ((arr_year_EXP[0] <= arr_year_TRANS[0]) && (arr_year_EXP[1] < arr_year_TRANS[1]))|| ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] >= arr_month_TRANS[1]))&&
		((arr_year_EXP[0] <= arr_year_TRANS[0]) && (arr_year_EXP[1] < arr_year_TRANS[1])))
	{
	printf("EXPIRED_CARD \n");
	return EXPIRED_CARD;
	}
			
	
	if (((arr_month_EXP[0] > arr_month_TRANS[0]) && (arr_month_EXP[1] < arr_month_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] > arr_month_TRANS[1]))
		|| ((arr_year_EXP[0] >= arr_year_TRANS[0]) && (arr_year_EXP[1] > arr_year_TRANS[1])) || ((arr_month_EXP[0] == arr_month_TRANS[0]) && (arr_month_EXP[1] < arr_month_TRANS[1]))
		&& ((arr_year_EXP[0] >= arr_year_TRANS[0]) && (arr_year_EXP[1] > arr_year_TRANS[1])))
	{
		printf("TERMINAL_OK \n");
		return TERMINAL_OK;
	}
		
		
	}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	ST_terminalData_t transAmount;
	printf("Please enter Transaction Amount : ");
	scanf("%f",&transAmount);
	*termData = transAmount;
	if (termData->transAmount == 0) {
		return INVALID_AMOUNT;
	}
	else
	{
		return TERMINAL_OK;
	}

}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	ST_terminalData_t maxTransAmount;
	printf("Please enter max Transaction Amount : ");
	scanf("%f", &termData->maxTransAmount);
	if ((termData->transAmount) > (termData->maxTransAmount))
	{
		printf("EXCEEDED_MAX_AMOUNT \n");
		return EXCEED_MAX_AMOUNT;
	}
	else
	{
		printf("TERMINAL_OK \n");
		return TERMINAL_OK;
	}

}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	ST_terminalData_t* maxTransAmount;
	printf("Please enter max Transaction Amount : ");
	scanf("%f", &maxAmount);
	termData->maxTransAmount= maxAmount;
	if (maxAmount <= 0) 
	{
		return INVALID_MAX_AMOUNT;
	}
	else
	{
	 return	TERMINAL_OK;
	}


}


void DisplayTerminalTest(void)
{
	uint8_t c;
	printf("choose one of these functions \n");
	printf("1-getTransactionDateTest \n");
	printf("2-isCardExpiredTest \n");
	printf("3-getTransactionAmountTest \n");
	printf("4-isBelowMaxAmountTest \n");
	printf("5-setMaxAmountTest \n");
	scanf("%d", &c);
	if (c == 1)
	{
		getTransactionDateTest();
	}
	else if (c == 2)
	{
		isCardExpiredTest();

	}
	else if (c == 3)
	{
		getTransactionAmountTest();

	}
	else if (c == 4) 
	{
		isBelowMaxAmountTest();
	}
	else if (c == 5) 
	{
		setMaxAmountTest();
	}
	else 
	{
	}
}