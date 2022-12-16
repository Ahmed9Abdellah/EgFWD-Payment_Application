#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"../Card/card.h"
#include"../Terminal/terminal.h"
#include"server.h"
#include"../STD_TYPES.h"



ST_accountsDB_t accountsDB[255]={ {1000, RUNNING,"777888999101010111"},
								{5000, RUNNING,  "123321456654789987"},
								{3000, BLOCKED,  "122134435665788791"},
								{2000, RUNNING,  "321654987456132798"},
								{9000, BLOCKED,  "100020003000400050"},
								{7000, RUNNING,  "100120023003400450"},
								{6000, BLOCKED,  "333556667788899101"},
								{1000, BLOCKED,  "123456543216789101"},
								{4000, RUNNING,  "993322556600101011"},
								{8000, RUNNING,  "998877665544332211"} };
 
  
 struct ST_transaction_t arrayTransaction[255] = { 0 };
 ST_accountsDB_t* ptr = 0;
 ST_transaction_t* TransactionRef = 0;
 ST_transaction_t* PtrSaved = 0;
 uint32_t TransactionIndex = 0;
 ST_cardData_t* PtrCard;
 ST_terminalData_t* PtrTerminal;
 EN_transState_t TransactionState = 0;


 void isValidAccountTest(void)
 {
	 uint8_t c;
	 uint8_t Tester_name[11];
	 uint8_t AccountNumber[20];
	 uint32_t AccountCompare = 0;
	 printf("Tester Name :");
	 scanf("%s", &Tester_name);
	 printf("Function Name : isValidAccount \n");
	 printf("Please enter Account Number :");
	 scanf("%s", &AccountNumber);
	 printf("Please enter case number \n");
	 scanf("%d", &c);
	 switch (c)
	 {
	 case 1:
		 printf("Test Case 1 \n");
		 printf("Input Data : %s \n", AccountNumber);
		 printf("Expected Result : SERVER_OK \n");

		 for (uint32_t i = 0; i < 10; i++) {

			 AccountCompare = strcmp((accountsDB[i].primaryAccountNumber), AccountNumber);
		 }
		 if (AccountCompare == 0)

		 {
			 printf("Actual Result : SERVER_OK \n");
		 }
		 break;
	 case 2:
		 printf("Test Case 2 \n");
		 printf("Input Data : %s \n", AccountNumber);
		 printf("Expected Result : ACCOUNT_NOT_FOUND \n");
		 for (uint32_t i = 0; i < 10; i++) {
			 AccountCompare = strcmp(accountsDB[i].primaryAccountNumber, AccountNumber);
			 if (AccountCompare != 0)
			 {
				 printf("Actual Result : ACCOUNT_NOT_FOUND");
				 break;
			 }
		 }
		 break;
	 }
 }
 void isBlockedAccountTest(void)
 {
	 uint8_t c;
	 uint8_t Tester_name[11];
	 uint8_t AccountNumber[20];
	 uint32_t AccountCompare = 0;

	 
	 printf("Tester Name :");
	 scanf("%s", &Tester_name);
	 printf("Function Name : isBlockedAccount \n");
	 printf("Please enter Account Number :");
	 scanf("%s", &AccountNumber);
	 printf("Please enter case number \n");
	 scanf("%d", &c);
	 switch (c)
	 {
	 case 1:
		 printf("Test Case 1 \n");
		 printf("Input Data : %s \n", AccountNumber);
		 printf("Expected Result : SERVER_OK \n");

		 for (uint32_t i = 0; i < 10; i++) {

			 AccountCompare = strcmp((accountsDB[i].primaryAccountNumber), AccountNumber);
			 if (AccountCompare == 0)
			 {
			 if (accountsDB[i].state==RUNNING) {
				 printf("Actual Result : SERVER_OK \n");
				
			 }
			 }
		 }

			 break;

	 case 2:

		 printf("Test Case 2 \n");
		 printf("Input Data : %s \n", AccountNumber);
		 printf("Expected Result : BLOCKED_ACCOUNT \n");
		 for (uint32_t i = 0; i < 10; i++) {
			 AccountCompare = strcmp(accountsDB[i].primaryAccountNumber, AccountNumber);
			 if (AccountCompare == 0)
			 {
				 if (accountsDB[i].state == BLOCKED) {

					 printf("Actual Result : BLOCKED_ACCOUNT \n");

			 }
			 }
			 
		 }
		 break;
	 }
	 
 }

 void isAmountAvailableTest(void)
 {
	 uint8_t c;
	 uint8_t Tester_name[11];
	 uint8_t AccountNumber[20];
	 uint32_t AccountCompare = 0;
	 float32_t transAmount;
	 printf("Tester Name :");
	 scanf("%s", &Tester_name);
	 printf("Function Name : isAmountAvailable \n");
	 printf("Please enter Account Number :");
	 scanf("%s", &AccountNumber);
	 printf("please enter Transaction Amount :");
	 scanf("%f", &transAmount);
	 printf("Please enter case number \n");
	 scanf("%d", &c);
	 switch (c)
	 {
	 case 1:
		 printf("Test Case 1 \n");
		 printf("Input Data : %s  %.2f\n", AccountNumber,transAmount);
		 printf("Expected Result : SERVER_OK \n");

		 for (uint32_t i = 0; i < 10; i++) {

			 AccountCompare = strcmp((accountsDB[i].primaryAccountNumber), AccountNumber);
			 if (AccountCompare == 0)
			 {
				 if  (transAmount   <= accountsDB[i].balance) {
					 printf("Actual Result : SERVER_OK \n");

				 }
			 }
		 }

		 break;

	 case 2:

		 printf("Test Case 2 \n");
		 printf("Input Data : %s  %.2f\n", AccountNumber,transAmount);
		 printf("Expected Result : LOW_BALANCE \n");
		 for (uint32_t i = 0; i < 10; i++) {
			 AccountCompare = strcmp(accountsDB[i].primaryAccountNumber, AccountNumber);
			 if (AccountCompare == 0)
			 {
				 if (accountsDB[i].balance < transAmount) {

					 printf("Actual Result : LOW_BALANCE \n");

				 }
			 }

		 }
		 break;
	 }

 }
  uint8_t recieveTransactionDataTest(ST_transaction_t* transData)
 {
	 uint8_t ReceiveTransactionErrorState = 0;

	 uint8_t ErrorState = recieveTransactionData(transData);

	 if (ErrorState == APPROVED)
	 {
		 printf(" APPROVED \n");
	 }
	 else if (ErrorState ==DECLINED_INSUFFECIENT_FUND)
	 {
		 printf(" DECLINED_INSUFFECIENT_FUND \n");
	 }
	 else if (ErrorState== DECLINED_STOLEN_CARD)
	 {
		 printf(" DECLINED_STOLEN_CARD \n");
	 }
	 else if ( ErrorState== INTERNAL_SERVER_ERROR)
	 {
		 printf("INTERNAL_SERVER_ERROR \n");
	 }
	 else
	 {
		 ReceiveTransactionErrorState = 1;
	 }

	 return ReceiveTransactionErrorState;
 }

 EN_transState_t recieveTransactionData(ST_transaction_t* transData)
 {

	
	 EN_serverError_t AmountValidity = 0;
	 EN_serverError_t AccountState = 0;
	 EN_serverError_t AmountAvaialbility = 0;
	 EN_serverError_t  TransactionSaved= 0;
	 ST_transaction_t* SavePtr = transData;

	
	 AmountValidity = isValidAccount(&PtrCard, &ptr);
	 AmountAvaialbility = isAmountAvailable(&PtrTerminal, &ptr);
	 AccountState = isBlockedAccount(&ptr);
	

	 if (AmountAvaialbility == LOW_BALANCE)
	 {
		 printf("DECLINED_INSUFFECIENT_FUND");
		 return DECLINED_INSUFFECIENT_FUND;
		 TransactionState = DECLINED_INSUFFECIENT_FUND;
	 }
	   else  if (AmountValidity == ACCOUNT_NOT_FOUND)
	 {
		 printf("FRAUD_CARD");
		return FRAUD_CARD;
		TransactionState = FRAUD_CARD;

	 }
	
	  else if (AccountState == BLOCKED_ACCOUNT)
	 {
	
		 printf("DECLINED_STOLEN_CARD");
		return DECLINED_STOLEN_CARD;
		TransactionState = DECLINED_STOLEN_CARD;
	 }
	 
	else{
		 printf("APPROVED");
		return APPROVED;
		 ptr->balance = ptr->balance - PtrTerminal->transAmount;
		 TransactionState = APPROVED;
	  }

	TransactionSaved = saveTransaction(&PtrSaved);
	 if (TransactionSaved != SERVER_OK)
	 {
		 printf("INTERNAL_SERVER_ERROR");
		return INTERNAL_SERVER_ERROR;
		
	 }

	
 }



 EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t* accountRefrence)
 {
	 
	 uint32_t PanCompare = 0;
	 ptr = 0;

	 for (uint16_t i = 0; i <10 ; i++)
	 {
		 PanCompare = 0;
		 PanCompare = strcmp(cardData->primaryAccountNumber, accountRefrence->primaryAccountNumber);

		 if (PanCompare == 0)
		 {
			 return SERVER_OK;
			 ptr = accountRefrence;
			 break;
		 }
		 accountRefrence++;
	 }

	 if (ptr == 0)
	 {
		 return ACCOUNT_NOT_FOUND;
	 }


 }
 EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence){
	
	
		 if (accountRefrence != 0)
		 {

			 if (accountRefrence->state == BLOCKED)
			 {
				
				 return BLOCKED_ACCOUNT;

			 }
			 else
			 {
				 return SERVER_OK;
				
			 }
		 }


		


	 }
 
 EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
 {
	 uint8_t AccountNumber[20];
	 uint32_t AccountCompare = 0;
	 printf("please enter Transaction Amount :");
	 scanf("%f", &termData->transAmount);
	 printf("please enter PAN to check Balance :");
	 scanf("%s", &AccountNumber);
	 if (accountRefrence != 0) {

		 for (uint32_t i = 0; i < 10; i++) {
			 AccountCompare = strcmp(accountsDB[i].primaryAccountNumber, AccountNumber);
			 if (AccountCompare == 0)
			 {
				 if (accountsDB[i].balance < termData->transAmount) {

					
					 return LOW_BALANCE;

				 }
				 else {
					 accountsDB[i].balance = accountsDB[i].balance - termData->transAmount;
					 printf("The current balance is : %f  ", accountsDB[i].balance);
						 return SERVER_OK;
				 }
			 }
		 }
	 }
 }
 void listSavedTransactions(void)
 {
	 
	 printf("#########################");
	 printf("\n");
	 printf("Transaction Sequence Number: %ld", TransactionRef->transactionSequenceNumber);
	 printf("\n");
	 printf("Transaction Date: %s", TransactionRef->terminalData.transactionDate);
	 printf("\n");
	 printf("Transaction Amount: %f", TransactionRef->terminalData.transAmount);
	 printf("\n");
	 switch (TransactionRef->transState)
	 {
	 case APPROVED:
		 printf("Transaction State: APPROVED");
		 break;

	 case DECLINED_INSUFFECIENT_FUND:
		 printf("Transaction State: DECLINED_INSUFFECIENT_FUND");
		 break;

	 case DECLINED_STOLEN_CARD:
		 printf("Transaction State: DECLINED_STOLEN_CARD ");
		 break;

	 case FRAUD_CARD:
		 printf("Transaction State: FRAUD_CARD ");
		 break;

	 case INTERNAL_SERVER_ERROR:
		 printf("Transaction State: Declined -> Internal Server Error");
		 break;
	 }
	 printf("\n");
	 printf("Terminal Max Amount: %f", TransactionRef->terminalData.maxTransAmount);
	 printf("\n");
	 printf("Cardholder Name: %s", TransactionRef->cardHolderData.cardHolderName);
	 printf("\n");
	 printf("PAN: %s", TransactionRef->cardHolderData.primaryAccountNumber);
	 printf("\n");
	 printf("Card Expiration Date: %s", TransactionRef->cardHolderData.cardExpirationDate);
	 printf("\n");
	 printf("#########################");
	 printf("\n");
 }

 EN_serverError_t saveTransaction(ST_transaction_t* transData)
 {
	 strcpy(transData->cardHolderData.cardHolderName, PtrCard->cardHolderName);
	 strcpy(transData->cardHolderData.cardExpirationDate, PtrCard->cardExpirationDate);
	 strcpy(transData->cardHolderData.primaryAccountNumber, PtrCard->primaryAccountNumber);

	 strcpy(transData->terminalData.transactionDate, PtrTerminal->transactionDate);
	 transData->terminalData.transAmount = PtrTerminal->transAmount;
	 transData->terminalData.maxTransAmount = PtrTerminal->maxTransAmount;

	 transData->transState = TransactionState;

	 transData->transactionSequenceNumber = 1 + TransactionIndex;

	 listSavedTransactions();

	 TransactionIndex++;
	 return SERVER_OK;
 }
 uint8_t listSavedTransactionsTest(ST_transaction_t* transData)
 {
	 EN_transState_t Transaction_Error_State = recieveTransactionData(transData);
	 ST_transaction_t* TransactionRef = 0;
	
	 uint8_t Tester_name[11];
	 uint8_t c;
	 printf("\n");
	 printf("Tester Name :");
	 scanf("\n %s", &Tester_name);
	 printf("Function Name : listSavedTransactions \n");
	 printf("please enter case number :");
	 scanf("%d", &c);

	 switch (c)
	 {
	 case 1:
		 printf("Test Case 1 \n");
		 printf("Expected Result : APPROVED: \n");
		 {
			 if (Transaction_Error_State == APPROVED);
			 printf("Actual Result : APPROVED ");
		 }
		 break;
	 case 2:
		 printf("Test Case 2 \n");
		 printf("Expected Result : DECLINED_INSUFFECIENT_FUND \n");
		 if (Transaction_Error_State == DECLINED_INSUFFECIENT_FUND) {
			 printf("Actual Result : DECLINED_INSUFFECIENT_FUND");
			 break;
		 }
	 case 3:
		 printf("Test Case 3 \n");
		 printf("Expected Result : DECLINED_STOLEN_CARD \n");
		 if (Transaction_Error_State == DECLINED_STOLEN_CARD) {
			 printf("Actual Result : DECLINED_STOLEN_CARD");
			 break;
		 }
	 case 4:
		 printf("Test Case 4 \n");
		 printf("Expected Result : FRAUD_CARD: \n");
		 if (Transaction_Error_State == FRAUD_CARD) {
			 printf("Actual Result : FRAUD_CARD:");
			 break;
	 case 5:
		 printf("Test Case 5 \n");
		 printf("Expected Result : INTERNAL_SERVER_ERROR: \n");
		 if (Transaction_Error_State == INTERNAL_SERVER_ERROR) {
			 printf("Actual Result : INTERNAL_SERVER_ERROR:");
			 break;
		 }
		 }
	 }
 }
 void saveTransactionTest(void)
 {
	 ST_transaction_t* transData=0;
	 uint8_t c;
	 uint8_t Tester_name[11];
	 float32_t maxTransAmount;
	 uint32_t transactionSequenceNumber;
	 printf("Tester Name :");
	 scanf("%s", &Tester_name);
	 printf("Function Name : SaveTransaction \n");
	 printf("Please enter max Transaction Amount :");
	 scanf("%f", &maxTransAmount);
	 printf("please enter transactionSequenceNumber : ");
	 scanf("%d", &transactionSequenceNumber);
	 printf("Please enter case number \n");
	 scanf("%d", &c);
	 switch (c)
	 {
	 case 1:
		 printf("Test Case 1 \n");
		 printf("Input Data : %.2f \n", maxTransAmount);
		 printf("Expected Result : SERVER_OK \n");
		 if (transactionSequenceNumber <maxTransAmount)
		 {
			 printf("Actual Result : SERVER_OK ");
		 }
		 break;
	 case 2:
		 printf("Test Case 2 \n");
		 printf("Input Data : %.2f \n", maxTransAmount);
		 printf("Expected Result : SAVING_FAILED \n");
		 if (transactionSequenceNumber > maxTransAmount ) {
			 printf("Actual Result : SAIVING_FAILED");
			 break;
		 }
	 }
	 }
	 void DisplayServerTest(void)
	 {
		 uint8_t c;
		 printf("choose one of these functions \n");
		 printf("1-isValidAccountTest \n");
		 printf("2-isBlockedAccountTest \n");
		 printf("3-isAmountAvailableTest \n");
		 printf("4-saveTransactionTest \n");
		 scanf("%d", &c);
		 if (c == 1)
		 {
			 isValidAccountTest();
		 }
		 else if (c == 2)
		 {
			 isBlockedAccountTest();

		 }
		 else if (c == 3)
		 {
			
			 isAmountAvailableTest();
		 }
		 else if (c == 4) {
			 saveTransactionTest();
		 }

	 }