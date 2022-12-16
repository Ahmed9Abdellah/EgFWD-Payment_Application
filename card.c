#include<string.h>
#include<stdio.h>
#include"../STD_TYPES.h"
#include"../Server/server.h"
#include"card.h"


ST_accountsDB_t accountDBS[255] = { {1000, RUNNING,"777888999101010111"},
								{5000, RUNNING,  "123321456654789987"},
								{3000, BLOCKED,  "122134435665788791"},
								{2000, RUNNING,  "321654987456132798"},
								{9000, BLOCKED,  "100020003000400050"},
								{7000, RUNNING,  "100120023003400450"},
								{6000, BLOCKED,  "333556667788899101"},
								{1000, BLOCKED,  "123456543216789101"},
								{4000, RUNNING,  "993322556600101011"},
								{8000, RUNNING,  "998877665544332211"} };

void getCardHolderNameTest(void)
{
	uint8_t y;
	uint8_t Tester_name[25], Card_Holder[25];

	printf("Tester Name:");
	scanf("%s", &Tester_name);
	printf("Function name: getCardHolderName \n");
	printf("Name of Card Holder : ");
	scanf("%s", &Card_Holder);
	printf("enter number of case : ");
	scanf("%d",&y);
	switch (y) {
	case 1:
		printf("Test Case 1 : \n");
		printf("Input data :  %s \n", Card_Holder);
		printf("Expected Result: CARD_OK \n");
		if (strlen(Card_Holder) == 20
			|| strlen(Card_Holder) == 21
			|| strlen(Card_Holder) == 22
			|| strlen(Card_Holder) == 23
			|| strlen(Card_Holder) == 24)
		{
			printf("Actual Result= CARD_OK \n");
		}
		break;
	case 2:
		printf("Test Case 2 : \n");
		printf("Input data : %s ", Card_Holder);
		printf("Expected Result: WRONG_NAME \n");
		if ((strlen(Card_Holder)) < 20 || (strlen(Card_Holder)) > 24  ) {
			printf("Actual Result= WRONG NAME");
		}
		break;
	case 3:
		printf("Test Case 3 : \n");
		printf("Input Data : %s ", Card_Holder);
		printf("Expected Result : WRONG_NAME \n");
		for (uint16_t i = 0; Card_Holder[i] != '\0'; i++)
		{
			if ((Card_Holder[i] >= '0' && Card_Holder[i] <= '9'))

			{
				printf("Actual Result= WRONG NAME");

				break;
			}
		}
		break;
	}
}
void getCardExpiryDateTest(void)
{
	uint8_t Expire_Date[6], c, Tester_name[25];
	printf("Tester Name: ");
	scanf("%s", &Tester_name);
	printf("Function Name : getCardExpiryDate \n");
	printf("please enter the expiration date : \n");
	scanf("%s", &Expire_Date);
	printf("enter numer of case : \n");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("Test Case 1 \n");
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : CARD_OK \n");
		if (strlen(Expire_Date) == 5) {
			printf("Actual Result : CARD_OK");
		}
		break;
	case 2:
		printf("Test Case 2 \n");
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : WRONG_EXP_DATE \n");
		if (strlen(Expire_Date) != 5) {
			printf("Actual Result : WRONG_EXP_DATE");
		}
		break;

	case 3:
		printf("Test Case 3 \n");
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : WRONG_EXP_DATE \n");
		for (uint16_t i = 0; Expire_Date[i] != '\0'; i++) {
			if ((Expire_Date[i] >= 'a' && Expire_Date[i] <= 'z') || (Expire_Date[i] >= 'A' && Expire_Date[i] <= 'Z'))
			{
				printf("Actual Result : WRONG_EXP_DATE");
				break;
			}

		}
			break;
	case 4:
		printf("Test Case 4 \n");
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : WRONG_EXP_DATE \n");
		if (Expire_Date[0] >= '2')
		{
				printf("Actual Result : WRONG_EXP_DATE");
				break;
			}

	 	  break;
	case 5:
		printf("Test Case 5 \n");
		printf("Input Data : %s \n", Expire_Date);
		printf("Expected Result : WRONG_EXP_DATE \n");
		if ((Expire_Date[0] < '1') && (Expire_Date[1] < '1') || (Expire_Date[3] < '1') && (Expire_Date[4] < '1'))
		{
			printf("Actual Result : WRONG_EXP_DATE");
			break;
		}

		break;
		  
	
	}

	

	
}
void getCardPANTest(void)
{
	uint32_t AccountCompare;
	uint8_t PAN[20], c;
	uint8_t Tester_name[25];
	uint8_t* ptr = &PAN;
	printf("Tester Name : ");
	scanf("%s", &Tester_name);
	printf("Enter The Primary Account Number (PAN) \n");
	scanf("%s", &PAN);
	ptr = &PAN;
	printf("please enter case number : ");
	scanf("%d", &c);
	switch (c)
	{
	case 1:
		printf("Test Case 1 : \n");
		printf("Input Data %s \n", PAN);
		printf("Expected Result : CARD_OK \n");
		if (strlen(PAN) == 16
			|| strlen(PAN) == 17
			|| strlen(PAN) == 18
			|| strlen(PAN) == 19)
		{
			printf("Actual Result= CARD_OK \n");
		}
		break;
	case 2:
		printf("Test Case 2 \n");
		printf("Input Data %s \n", PAN);
		printf("Expected Result : WRONG_PAN \n");
		if (strlen(PAN) < 16 || strlen(PAN) > 19 || ptr == NULL)
		{
			printf("Actual Result : WRONG_PAN");
		}
		break;

	case 3:
		printf("Test Case 3 \n");
		printf("Input Data %s \n", PAN);
		printf("Expected Result : DECLINED_STOLEN_CARD \n");
		for (uint16_t i = 0; PAN[i] != '\0'; i++)
		{
			AccountCompare = strcmp(accountDBS[i].primaryAccountNumber, PAN);
			if (AccountCompare == 0)
			{

				if (accountDBS[i].state == BLOCKED)
				{

					printf("Actual Result : DECLINED_STOLEN_CARD \n");
					exit(0);
				}

			}

		}

		break;
	case 4:
		printf("Test Case 4 \n");
		printf("Input Data %s \n", PAN);
		printf("Expected Result : WRONG_PAN \n");
		for (uint16_t i = 0; PAN[i] != '\0'; i++)
			if ((PAN[i] >= 'a') && (PAN[i] <= 'z')
				|| (PAN[i] >= 'A') && (PAN[i] <= 'Z'))

			{
				printf("Actual Result : WRONG_PAN");
			}
		break;

	}
}
	

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("please enter card holder's name : ");
	gets(cardData->cardHolderName);

	if (strlen(cardData->cardHolderName) >= 20 && strlen(cardData->cardHolderName) <= 24)
	{
		for (uint16_t i = 0; cardData->cardHolderName[i] != '\0'; i++)
		{
			if ((cardData->cardHolderName[i] >= '0' && cardData->cardHolderName[i] <= '9'))

			{

				return WRONG_NAME;
			}

		}
	}
	else
	{
		return WRONG_NAME;
	}
	return CARD_OK;
}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint16_t len;
	printf("please enter the expiration date : ");

	gets(cardData->cardExpirationDate);
	len = strlen(cardData->cardExpirationDate);
	if (len != 5)
	{
		return WRONG_EXP_DATE;
	}
	for (uint16_t i = 0; cardData->cardExpirationDate[i] != '\0'; i++) {
		if ((cardData->cardExpirationDate[i] >= 'a' && cardData->cardExpirationDate[i] <= 'z') || (cardData->cardExpirationDate[i] >= 'A' && cardData->cardExpirationDate[i] <= 'Z'))

	
		{
			return WRONG_EXP_DATE;

		}
	}


	if (cardData->cardExpirationDate[0] >= '2')
	{
		return WRONG_EXP_DATE;
	}
	else if ((cardData->cardExpirationDate[0] < '1') && (cardData->cardExpirationDate[1] < '1') || (cardData->cardExpirationDate[3] < '1') && (cardData->cardExpirationDate[4] < '1'))
	{
		return WRONG_EXP_DATE;
	}

	else {
		return CARD_OK;
	}
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint16_t len;
	ST_accountsDB_t* ptr = 0;
	uint32_t AccountCompare = 0;
	printf("Enter Card Pan : ");
	gets(cardData->primaryAccountNumber);
	len = strlen(cardData->primaryAccountNumber);
	for (uint16_t i = 0; cardData->primaryAccountNumber[i] != '\0'; i++)
	{
		AccountCompare = strcmp(accountDBS[i].primaryAccountNumber, cardData->primaryAccountNumber);
		if (AccountCompare == 0)
		{

			if (accountDBS[i].state == BLOCKED)
			{

				printf("DECLINED_STOLEN_CARD \n");
				exit(0);
			}

		}
	}

	if ((len >= 16) && (len <= 19))
	{
		for (uint16_t i = 0; cardData->primaryAccountNumber[i] != '\0'; i++) {
			if ((cardData->primaryAccountNumber[i] >= 'a') && (cardData->primaryAccountNumber[i] <= 'z')
				|| (cardData->primaryAccountNumber[i] >= 'A') && (cardData->primaryAccountNumber[i] <= 'Z'))

			{
				return WRONG_PAN;
			}

		}
	}
	else {
		return WRONG_PAN;
	}
	return CARD_OK;
}
void DisplayCardTest(void)
{
	uint8_t c;
	printf("choose one of these functions \n");
	printf("1-getCardHolderNameTest \n");
	printf("2-getCardExpiryDateTest \n");
	printf("3-getCardPANTest \n");
	printf("please choose one of these functions : ");
	scanf("%d", &c);
	if(c==1)
	{
		getCardHolderNameTest();
	}
	else if (c == 2)
	{
		getCardExpiryDateTest();

	}
	else if (c == 3)
	{
		getCardPANTest();

	}
	else {}

}