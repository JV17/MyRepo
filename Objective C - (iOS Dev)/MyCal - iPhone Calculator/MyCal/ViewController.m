//
//  ViewController.m
//  dummycal
//
//  Created by Jorge Valbuena on 2014-04-16.
//  Copyright (c) 2014 Jorge Valbuena. All rights reserved.
//

#import "ViewController.h"

// private properties
@interface ViewController ()

@property (nonatomic) BOOL userIsInTheMiddleOfEntereingANumber;
@property (nonatomic) BOOL userSelfEquals;
@property(assign,nonatomic) NSInteger Method;
@property (nonatomic, strong) IBOutlet UIButton *Dot;
@property(nonatomic, strong) NSNumber *number;
@property (nonatomic, strong) NSString *inputString;
@property (nonatomic, strong) NSString *display;

@end

@implementation ViewController

@synthesize Dot;
@synthesize Screen;
@synthesize Method;
@synthesize userIsInTheMiddleOfEntereingANumber = _userIsInTheMiddleOfEntereingANumber;
@synthesize number;
@synthesize inputString;
@synthesize userSelfEquals;
@synthesize display;

@synthesize button0;
@synthesize button1;
@synthesize button2;
@synthesize button3;
@synthesize button4;
@synthesize button5;
@synthesize button6;
@synthesize button7;
@synthesize button8;
@synthesize button9;
@synthesize buttonAllClear;
@synthesize buttonDivide;
@synthesize buttonDot;
@synthesize buttonEquals;
@synthesize buttonPercent;
@synthesize buttonPlus;
@synthesize buttonPositiveOrNegative;
@synthesize buttonSubstract;
@synthesize buttonTimes;

double result;
double screenF;

// take the current value of self.inputString, and use NSNumberFormatter to give us a @"1,234,567.89" string.
- (NSString *)fancyString {
    NSNumberFormatter *numberFormat = [[NSNumberFormatter alloc] init];
    
    numberFormat.usesGroupingSeparator = YES;
    
    numberFormat.groupingSeparator = @",";
    
    numberFormat.groupingSize = 3;
    
    [numberFormat setMaximumFractionDigits:6];
    
    [numberFormat setNumberStyle:NSNumberFormatterDecimalStyle];
    
    return [numberFormat stringFromNumber:self.numericalValue];
}


// take the current value of self.inputString, and use NSNumberFormatter to give us a number, as a NSNumber, like 1234567.89
- (NSNumber *)numericalValue {

    NSNumberFormatter *numberFormat = [[NSNumberFormatter alloc] init];
    
    [numberFormat setNumberStyle:NSNumberFormatterDecimalStyle];
    
    //self.number = [numberFormat numberFromString:self.Screen.text];
    
    return [numberFormat numberFromString:self.inputString];
}


// take the current value of self.Screen.text to use for multiple calculations at the same time
- (NSNumber *)screenValue {
    
    NSNumberFormatter *numberFormat = [[NSNumberFormatter alloc] init];
    
    [numberFormat setNumberStyle:NSNumberFormatterDecimalStyle];
    
    return [numberFormat numberFromString:self.Screen.text];
}


-(IBAction)Number1:(UIButton *)sender{
    [self appendDigit:@"1"];
}


-(IBAction)Number2:(UIButton *)sender{
    [self appendDigit:@"2"];
}


-(IBAction)Number3:(UIButton *)sender{
    [self appendDigit:@"3"];
}


-(IBAction)Number4:(UIButton *)sender{
    [self appendDigit:@"4"];
}


-(IBAction)Number5:(UIButton *)sender{
    [self appendDigit:@"5"];
}


-(IBAction)Number6:(UIButton *)sender{
    [self appendDigit:@"6"];
}


-(IBAction)Number7:(UIButton *)sender{
    [self appendDigit:@"7"];
}


-(IBAction)Number8:(UIButton *)sender{
    [self appendDigit:@"8"];
}


-(IBAction)Number9:(UIButton *)sender{
    [self appendDigit:@"9"];
}


-(IBAction)Number0:(UIButton *)sender{
    [self appendDigit:@"0"];
}


- (IBAction)Dot:(UIButton *)sender {
    
    NSString *currentText = Screen.text;
    if ([currentText rangeOfString:@"." options:NSBackwardsSearch].length == 0) {
        [self appendDigit:@"."];
    }
}


- (void)appendDigit:(NSString *)digit {
    
    if ([self.Screen.text isEqualToString:@"0"] && ![digit isEqualToString:@"."]) {
        
        self.inputString = digit;
        
        if([self.Screen.text length] > 2){
            
            self.Screen.text = [self fancyString];
        
        } else {
            self.Screen.text = inputString;
        }
        
    } else if(self.userIsInTheMiddleOfEntereingANumber) {
    
        self.inputString = digit;
        
        if([self.Screen.text length] > 2){
            
            self.Screen.text = [self fancyString];
            
        } else {
            
            self.Screen.text = inputString;
        
        }
        
        self.userIsInTheMiddleOfEntereingANumber = NO;

    } else {
        
        if([self.Screen.text length] >= 15 || [self.Screen.text length] > 15){
            
            if([self.Screen.text length] > 2){
                
                self.Screen.text = [self fancyString];
                
            } else {
                
                self.Screen.text = inputString;
            
            }
        
        } else {
            
            self.inputString = [self.inputString stringByAppendingString:digit];
            
            if([self.Screen.text length] > 2){
                
                self.Screen.text = [self fancyString];
                
            } else {
                
                self.Screen.text = inputString;
                
            }
            
        }
    }
}


-(IBAction)Times:(UIButton *)sender{
    
    if(self.userSelfEquals){
        
        self.Method = 1;
        
        if(self.userIsInTheMiddleOfEntereingANumber)
            screenF = result;
        else
            [self MyOperations];
        
        self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
        
        if([self.display length] > 15){
            self.Screen.text = @"Too long :(";
        } else {
            self.Screen.text = self.display;
        }
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        screenF = result;
    }
    else {
        
        screenF = [[self screenValue] doubleValue];
        
        self.Method = 1;
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        self.userSelfEquals = YES;
    }
}


-(IBAction)Divide:(UIButton *)sender{
    
    if(self.userSelfEquals){
        
        self.Method = 2;
        
        if(self.userIsInTheMiddleOfEntereingANumber)
            screenF = result;
        else
            [self MyOperations];
        
        self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
        
        if([self.display length] > 15){
            self.Screen.text = @"Too long :(";
        } else {
            self.Screen.text = self.display;
        }
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        screenF = result;
    }
    else {
        
        screenF = [[self screenValue] doubleValue];
        
        self.Method = 2;
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        self.userSelfEquals = YES;
    }
}


-(IBAction)Substract:(UIButton *)sender{
    
    if(self.userSelfEquals){
        
        self.Method = 3;
        
        if(self.userIsInTheMiddleOfEntereingANumber)
            screenF = result;
        else
            [self MyOperations];
        
        self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
        
        if([self.display length] > 15){
            self.Screen.text = @"Too long :(";
        } else {
            self.Screen.text = self.display;
        }
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        screenF = result;
    }
    else {
        
        screenF = [[self screenValue] doubleValue];
        
        self.Method = 3;
        
        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        self.userSelfEquals = YES;
    }
}


-(IBAction)Plus:(UIButton *)sender{
    
    if(self.userSelfEquals){
        
        self.Method = 4;
        
        if(self.userIsInTheMiddleOfEntereingANumber)
            screenF = result;
        else
            [self MyOperations];
        
        self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
        
        if([self.display length] > 15){
            self.Screen.text = @"Too long :(";
        } else {
            self.Screen.text = self.display;
        }

        self.userIsInTheMiddleOfEntereingANumber = YES;
        
        screenF = result;
        
    }
    else {
    
        screenF = [[self screenValue] doubleValue];
    
        self.Method = 4;
    
        self.userIsInTheMiddleOfEntereingANumber = YES;
    
        self.userSelfEquals = YES;
    }
}


- (IBAction)Percent:(UIButton *)sender {
    
    screenF = [[self screenValue] doubleValue];
    
    self.Method = 5;
    
    [self MyOperations];
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
    
    self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
    
    if([self.display length] > 15){
        self.Screen.text = @"Error :(";
    } else {
        self.Screen.text = self.display;
    }
}


- (IBAction)PositiveOrNegative:(UIButton *)sender {
    
    screenF = [[self screenValue] doubleValue];
    
    self.Method = 6;
    
    [self MyOperations];
    
    self.userIsInTheMiddleOfEntereingANumber = YES;
    
    self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
    
    if([self.display length] > 15){
        self.Screen.text = @"Error :(";
    } else {
        self.Screen.text = self.display;
    }
}


-(IBAction)Equals:(UIButton *)sender{
    
    [self MyOperations];
    
    self.display = [NSNumberFormatter localizedStringFromNumber:@(result)                                                             numberStyle:NSNumberFormatterDecimalStyle];
    
    if([self.display length] > 15){
        self.Screen.text = @"Error :(";
    } else {
        self.Screen.text = self.display;
    }
    
    self.Method = 0;
    
    self.userIsInTheMiddleOfEntereingANumber = NO;
    
    self.userSelfEquals = NO;
    
}


-(IBAction)AllClear:(UIButton *)sender{
    
    Method = 0;

    result = 0;
    
    self.userIsInTheMiddleOfEntereingANumber = NO;
    
    self.userSelfEquals = NO;
    
    Screen.text = [NSString stringWithFormat:@"0"];
    
}


 - (double) MyOperations{
    
     double runningF = [[self screenValue] doubleValue];
     
     result = 0;
     
     if(!self.Method){
         result = runningF;
     } else {
         switch (self.Method) {
             case 1:
                 result = screenF * runningF;
                 break;
             case 2:
                 result = (runningF == 0.0)? 0.0 : screenF / runningF;
                 break;
             case 3:
                 result = screenF - runningF;
                 break;
             case 4:
                 result = screenF + runningF;
                 break;
             case 5:
                 result = screenF / 100;
                 break;
             case 6:
                 result = screenF *= -1;
                 break;
             default:
                 break;
         }
     }
     
     return result;
}


- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    self.Screen.text = @"0";
    
    self.Screen.numberOfLines = 1;
    self.Screen.adjustsFontSizeToFitWidth = YES;
    self.Screen.minimumScaleFactor = 0.5f;

    
    [self.button1 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button2 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button3 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button4 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button5 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button6 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button7 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button8 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button9 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.button0 setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonPositiveOrNegative setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonPlus setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonPercent setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonEquals setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonAllClear setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonDivide setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonSubstract setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonDot setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    [self.buttonTimes setBackgroundImage:[UIImage imageNamed:@"ButtonPressed.png"] forState:(UIControlStateHighlighted)];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end