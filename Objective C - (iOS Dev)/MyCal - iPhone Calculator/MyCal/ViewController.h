//
//  ViewController.h
//  dummycal
//
//  Created by Jorge Valbuena on 2014-04-16.
//  Copyright (c) 2014 Jorge Valbuena. All rights reserved.
//
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

@interface ViewController : UIViewController

@property(strong,nonatomic) IBOutlet UILabel *Screen;


@property (weak, nonatomic) IBOutlet UIButton *button1;
@property (weak, nonatomic) IBOutlet UIButton *button2;
@property (weak, nonatomic) IBOutlet UIButton *button3;
@property (weak, nonatomic) IBOutlet UIButton *button4;
@property (weak, nonatomic) IBOutlet UIButton *button5;
@property (weak, nonatomic) IBOutlet UIButton *button6;
@property (weak, nonatomic) IBOutlet UIButton *button7;
@property (weak, nonatomic) IBOutlet UIButton *button8;
@property (weak, nonatomic) IBOutlet UIButton *button9;
@property (weak, nonatomic) IBOutlet UIButton *button0;
@property (weak, nonatomic) IBOutlet UIButton *buttonTimes;
@property (weak, nonatomic) IBOutlet UIButton *buttonDivide;
@property (weak, nonatomic) IBOutlet UIButton *buttonSubstract;
@property (weak, nonatomic) IBOutlet UIButton *buttonPercent;
@property (weak, nonatomic) IBOutlet UIButton *buttonDot;
@property (weak, nonatomic) IBOutlet UIButton *buttonPositiveOrNegative;
@property (weak, nonatomic) IBOutlet UIButton *buttonEquals;
@property (weak, nonatomic) IBOutlet UIButton *buttonPlus;
@property (weak, nonatomic) IBOutlet UIButton *buttonAllClear;

-(IBAction)Number1:(UIButton *)sender;
-(IBAction)Number2:(UIButton *)sender;
-(IBAction)Number3:(UIButton *)sender;
-(IBAction)Number4:(UIButton *)sender;
-(IBAction)Number5:(UIButton *)sender;
-(IBAction)Number6:(UIButton *)sender;
-(IBAction)Number7:(UIButton *)sender;
-(IBAction)Number8:(UIButton *)sender;
-(IBAction)Number9:(UIButton *)sender;
-(IBAction)Number0:(UIButton *)sender;
-(IBAction)Times:(UIButton *)sender;
-(IBAction)Divide:(UIButton *)sender;
-(IBAction)Substract:(UIButton *)sender;
-(IBAction)Percent:(UIButton *)sender;
-(IBAction)Dot:(UIButton *)sender;
-(IBAction)PositiveOrNegative:(UIButton *)sender;
-(IBAction)Equals:(UIButton *)sender;
-(IBAction)Plus:(UIButton *)sender;
-(IBAction)AllClear:(UIButton *)sender;
-(double)MyOperations;
- (void)appendDigit:(NSString *)digit;
- (NSNumber *)fancyString;
- (NSNumber *)numericalValue;
- (NSNumber *)screenValue;
//- (IBAction)buttonPressed:(id)sender;
@end