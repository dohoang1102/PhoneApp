//
//  SignInVC.h
//  GiftGiv
//
//  Created by Srinivas G on 19/07/12.
//  Copyright (c) 2012 Teleparadigm Networks Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CheckNetwork.h"
#import "ApplicationHelpers.h"
#import "Facebook_GiftGiv.h"
#import "HomeScreenVC.h"
#import "MBProgressHUD.h"
#import "AddUserRequest.h"
#import "CoomonRequestCreationObject.h"

@interface SignInVC : UIViewController<Facebook_GiftGivDelegate,MBProgressHUDDelegate,AddUserRequestDelegate>
{
    MBProgressHUD *HUD;
}

- (IBAction)logInAction:(id)sender;
- (IBAction)termsAction:(id)sender;

- (void) showProgressHUD:(UIView *)targetView withMsg:(NSString *)titleStr;
- (void)stopHUD;

@end
