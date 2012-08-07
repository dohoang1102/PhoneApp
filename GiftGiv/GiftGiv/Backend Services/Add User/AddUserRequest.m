//
//  AddUserRequest.m
//  GiftGiv
//
//  Created by Srinivas G on 07/08/12.
//  Copyright (c) 2012 Teleparadigm Networks Limited. All rights reserved.
//

#import "AddUserRequest.h"

@implementation AddUserRequest
@synthesize addUserDelegate;


-(void)addUserServiceRequest:(NSMutableURLRequest *)request{
	
    
	//Asynchronous URL connection
	NSURLConnection *theConnection = [[NSURLConnection alloc] initWithRequest:request delegate:self startImmediately:YES];
	
	if( theConnection ){
		webData = [[NSMutableData alloc] init];
	}
	else
		NSLog(@"theConnection is NULL");
}
#pragma mark -
#pragma mark Connection delegates
//connection received data

- (void)connection:(NSURLConnection *)connection didReceiveData:(NSData *)data{
	
	[webData appendData:data];
}

//Connection finished successful
- (void)connectionDidFinishLoading:(NSURLConnection *)connection{
	
	//parsing the whole data which we got from the request
	NSXMLParser *xmlParser=[[NSXMLParser alloc]initWithData:webData];
    
    /*NSString * theXML = [[NSString alloc] initWithData:(NSData*) webData encoding:NSASCIIStringEncoding];
     NSLog(@"XML...%@",theXML);*/
	[webData release];
	
	[xmlParser setDelegate:self];
    receivedResponse=[[NSMutableString alloc]init];
	
	//delegate method to send the response after parsing finished successfully
	if([xmlParser parse]){
		[addUserDelegate responseForAddUser:receivedResponse];
	}
	[receivedResponse  release];
	[xmlParser release];
	[connection release];
}

//connection failed

- (void)connection:(NSURLConnection *)connection didFailWithError:(NSError *)error{
	
	//delegate method to indicate connection failed
	[delegate requestFailed];
	[webData release];
	[connection release];
}

#pragma mark -
#pragma mark xmlParser delegates
-(void) parser:(NSXMLParser*) parser didStartElement:(NSString*) argElementName namespaceURI:(NSString*) argNamespaceURI qualifiedName:(NSString*) argQualifiedName attributes:(NSDictionary*) attributeDict
{
	
}
- (void)parser:(NSXMLParser *)parser foundCharacters:(NSString *)string { 
	
	if(!currentElementValue) 
		currentElementValue = [[NSMutableString alloc] initWithString:string];
	else
		[currentElementValue appendString:string];
	
}

-(void) parser:(NSXMLParser*) parser didEndElement:(NSString*) argElementName namespaceURI:(NSString*) argNamespaceURI qualifiedName:(NSString*) argQualifiedName
{
	
	if([argElementName isEqualToString:@"AddUserResult" ]){
        receivedResponse=currentElementValue;
		
	}
	currentElementValue=nil;
	[currentElementValue release];
}
#pragma mark -
- (void) dealloc {
	
    
	[super dealloc];
}
@end
