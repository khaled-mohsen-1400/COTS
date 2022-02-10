/**************************************************************/
/***********     Author    :  SALAHELDIN             **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  04-10-2020             **********/
/***********     File      :  ESP_config             **********/
/**************************************************************/
#ifndef _ESP_CONFIG_H
#define _ESP_CONFIG_H

/****************************************************************/
/******                        MACROs                   *********/
/****************************************************************/
/*define recieving timout for each command that if it exceeded it means no more data*/
/*It varies depending on the router and server and also Clock freq, you'll need to try it*/
#define ECHO_TIMEOUT		100
#define MODE_TIMEOUT		2000
#define ROUTER_TIMEOUT		100000
#define SERVER_TIMEOUT		400000
#define PREREQUEST_TIMEOUT	5000        //Send CMD
#define REQUEST_TIMEOUT		400000		// Receive GET Request



#endif
