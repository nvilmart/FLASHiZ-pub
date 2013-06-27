//
//  RegisterViewController.h
//  iMobey
//
//  Created by ytf on 07/09/11.
//  Copyright (c) 2011 InTech S.A.. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MBProgressHUD.h"

@protocol RegisterViewControllerDelegate;

@interface RegisterViewController : UIViewController<UIWebViewDelegate,MBProgressHUDDelegate>{
    
    
     MBProgressHUD *HUD; 
    
}

@property (retain, nonatomic) IBOutlet UIWebView *webView;
@property (nonatomic, assign) id <RegisterViewControllerDelegate> delegate;

- (IBAction)back:(id)sender;

@end

@protocol RegisterViewControllerDelegate
- (void)connectionControllerBackRegister;
@end