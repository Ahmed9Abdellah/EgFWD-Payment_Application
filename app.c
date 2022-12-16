#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "app.h"

void appStart(void)
{
    ST_transaction_t transData[255] = { 0 };
    ST_cardData_t Card;

    EN_cardError_t CardHolderName_Error_State = getCardHolderName(&Card);

    if ((WRONG_NAME == CardHolderName_Error_State))
    {
        printf("Invalid Card Name.");
        return WRONG_NAME;
    }
    else
    {
    }


    EN_cardError_t CardExpDate_Error_State = getCardExpiryDate(&Card);

    if ((WRONG_EXP_DATE == CardExpDate_Error_State))
    {
        printf("Invalid Card Expiration Date.");
        return WRONG_EXP_DATE;
    }
    else
    {
    }


    EN_cardError_t CardPAN_Error_State = getCardPAN(&Card);

    if ((WRONG_PAN == CardPAN_Error_State))
    {
        printf("Invalid Card PAN.");
        return WRONG_PAN;
    }
    else
    {
    }


    ST_terminalData_t Terminal;


    Terminal.transAmount = 20000.0;


    EN_terminalError_t GetTransDate_Error_State = getTransactionDate(&Terminal);

    if ((WRONG_DATE == GetTransDate_Error_State))
    {
        printf("Invalid Transaction Date.");
        return WRONG_DATE;
    }
    else
    {
    }


    EN_terminalError_t ExpiredCard_Error_State = isCardExpired(&Card, &Terminal);
    if ((EXPIRED_CARD == ExpiredCard_Error_State))
    {
        printf("Card is expired.");
        return EXPIRED_CARD;
    }
    else
    {
    }
    EN_terminalError_t TransAmount_Error_State = getTransactionAmount(&Terminal);

    if ((INVALID_AMOUNT == TransAmount_Error_State))
    {
        printf("Invalid Transaction Amount.");
        return INVALID_AMOUNT;
    }
    else
    {
    }

    EN_terminalError_t TransAmountLimit_Error_State = isBelowMaxAmount(&Terminal);
    if ((EXCEED_MAX_AMOUNT == TransAmountLimit_Error_State))
    {
        printf("Transaction Amount Exceeded limit.");
        return EXCEED_MAX_AMOUNT;
    }
    else
    {
    }

    ST_transaction_t Transaction = { .cardHolderData = Card,
                                    .terminalData = Terminal,
    };
    EN_transState_t Transaction_Error_State = recieveTransactionData(&Transaction);
    if ((DECLINED_INSUFFECIENT_FUND == Transaction_Error_State))
    {
       // printf("DECLINED_INSUFFECIENT_FUND");
        return DECLINED_INSUFFECIENT_FUND;
    }
   
    else if ((INTERNAL_SERVER_ERROR == Transaction_Error_State))
    {
       // printf("Inernal Server Error.");
        return INTERNAL_SERVER_ERROR;
    }
    else if ((DECLINED_STOLEN_CARD == Transaction_Error_State))
    {
        //printf("Invalid Account.");
        return DECLINED_STOLEN_CARD;

    }
 

    else
    {
      //  printf("APPROVED \n");
        return APPROVED;

    }
    
}

