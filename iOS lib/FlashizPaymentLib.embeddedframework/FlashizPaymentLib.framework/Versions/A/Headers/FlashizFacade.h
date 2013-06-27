//
//  FlashizFacade.h
//  FlashIzMobilePaymentLib
//
//  Created by David Ledanseur on 08/02/12.
//  Copyright (c) 2012 InTech. All rights reserved.
//

/*It is the main object of the API*/

#import <UIKit/UIKit.h>
#import "ConnectionViewController.h"
#import "MakePaymentViewController.h"
#import "RegisterViewController.h"


typedef enum {
    FE_INTERNAL,
    FE_TEST,
    FE_PRODUCTION
} FlashizEnvironment ;


@protocol FlashizPaymentDelegate <NSObject>

-(void) paymentAcceptedForInvoice:(NSString*) invoiceId;
-(void) paymentCanceledForInvoice:(NSString*) invoiceId;

@end 



@interface FlashizFacade : NSObject <ConnectionViewControllerDelegate,MakePaymentViewControllerDelegate,PinCodeControllerViewDelegate,RegisterViewControllerDelegate>{
    @private
    
}

@property(nonatomic,retain) NSString* environment;
@property(nonatomic,retain) id<FlashizPaymentDelegate> delegate;
@property(nonatomic,retain) UIViewController* parentViewController;
@property(nonatomic,retain) UIViewController* connectionViewController;
@property(nonatomic,retain) UIViewController* registerViewController;
@property(nonatomic,retain) UIViewController* makePaymentViewController;
@property(nonatomic,retain) UIViewController* pinCodePaymentController;
@property Boolean modal;


@property(nonatomic,retain) NSString* invoiceId;

-(id) init;
-(id) initWithEnvironment:(FlashizEnvironment) env;
-(id) initWithEnvironment:(FlashizEnvironment) env lang:(NSString*)lang;
-(void) executePaymentForInvoiceId:(NSString*) invoiceId;


@end
