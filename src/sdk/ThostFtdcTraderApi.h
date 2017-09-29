/////////////////////////////////////////////////////////////////////////
///@system ¿¿¿¿¿¿¿¿
///@company ¿¿¿¿¿¿¿¿¿¿¿¿
///@file ThostFtdcTraderApi.h
///@brief ¿¿¿¿¿¿¿¿
///@history 
///20060106 ¿¿¿    ¿¿¿¿¿
/////////////////////////////////////////////////////////////////////////

#if !defined(THOST_FTDCTRADERAPI_H)
#define THOST_FTDCTRADERAPI_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ThostFtdcUserApiStruct.h"

#if defined(ISLIB) && defined(WIN32)
#ifdef LIB_TRADER_API_EXPORT
#define TRADER_API_EXPORT __declspec(dllexport)
#else
#define TRADER_API_EXPORT __declspec(dllimport)
#endif
#else
#define TRADER_API_EXPORT 
#endif

class CThostFtdcTraderSpi
{
public:
  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnFrontConnected(){};
  
  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿API¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  ///@param nReason ¿¿¿¿
  ///        0x1001 ¿¿¿¿¿
  ///        0x1002 ¿¿¿¿¿
  ///        0x2001 ¿¿¿¿¿¿
  ///        0x2002 ¿¿¿¿¿¿
  ///        0x2003 ¿¿¿¿¿¿
  virtual void OnFrontDisconnected(int nReason){};
    
  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  ///@param nTimeLapse ¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnHeartBeatWarning(int nTimeLapse){};
  
  ///¿¿¿¿¿¿¿
  virtual void OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};
  

  ///¿¿¿¿¿¿
  virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿
  virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿
  virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿
  virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿/¿¿¿¿¿¿¿¿
  virtual void OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿
  virtual void OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿
  virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿
  virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) {};

  ///¿¿¿¿
  virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) {};

  ///¿¿¿¿¿¿¿
  virtual void OnRtnBulletin(CThostFtdcBulletinField *pBulletin) {};

  ///¿¿¿¿
  virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) {};

  ///¿¿¿¿¿¿¿¿¿
  virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) {};

  ///¿¿¿¿¿¿
  virtual void OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿
  virtual void OnRtnQuote(CThostFtdcQuoteField *pQuote) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿
  virtual void OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿
  virtual void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) {};

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿
  virtual void OnRtnCombAction(CThostFtdcCombActionField *pCombAction) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) {};

  ///¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount) {};

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount) {};
};

class TRADER_API_EXPORT CThostFtdcTraderApi
{
public:
  ///¿¿TraderApi
  ///@param pszFlowPath ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  ///@return ¿¿¿¿UserApi
  static CThostFtdcTraderApi *CreateFtdcTraderApi(const char *pszFlowPath = "");
  
  ///¿¿API¿¿¿¿¿
  ///@retrun ¿¿¿¿¿¿¿
  static const char *GetApiVersion();
  
  ///¿¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿¿¿¿¿¿,¿¿¿¿¿¿¿¿¿¿¿
  virtual void Release() = 0;
  
  ///¿¿¿
  ///@remark ¿¿¿¿¿¿¿,¿¿¿¿¿,¿¿¿¿¿¿¿
  virtual void Init() = 0;
  
  ///¿¿¿¿¿¿¿¿¿¿
  ///@return ¿¿¿¿¿¿
  virtual int Join() = 0;
  
  ///¿¿¿¿¿¿¿
  ///@retrun ¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿¿¿,¿¿¿¿¿¿¿¿¿¿
  virtual const char *GetTradingDay() = 0;
  
  ///¿¿¿¿¿¿¿¿¿
  ///@param pszFrontAddress¿¿¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿¿¿¿¿¿protocol://ipaddress:port¿¿¿¿¿tcp://127.0.0.1:17001¿¿ 
  ///@remark ¿tcp¿¿¿¿¿¿¿¿¿127.0.0.1¿¿¿¿¿¿¿¿¿¿17001¿¿¿¿¿¿¿¿¿¿
  virtual void RegisterFront(char *pszFrontAddress) = 0;
  
  ///¿¿¿¿¿¿¿¿¿¿¿
  ///@param pszNsAddress¿¿¿¿¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿¿¿¿¿¿protocol://ipaddress:port¿¿¿¿¿tcp://127.0.0.1:12001¿¿ 
  ///@remark ¿tcp¿¿¿¿¿¿¿¿¿127.0.0.1¿¿¿¿¿¿¿¿¿¿12001¿¿¿¿¿¿¿¿¿¿
  ///@remark RegisterNameServer¿¿¿RegisterFront
  virtual void RegisterNameServer(char *pszNsAddress) = 0;
  
  ///¿¿¿¿¿¿¿¿¿¿¿
  ///@param pFensUserInfo¿¿¿¿¿¿
  virtual void RegisterFensUserInfo(CThostFtdcFensUserInfoField * pFensUserInfo) = 0;
  
  ///¿¿¿¿¿¿
  ///@param pSpi ¿¿¿¿¿¿¿¿¿¿¿
  virtual void RegisterSpi(CThostFtdcTraderSpi *pSpi) = 0;
  
  ///¿¿¿¿¿¿
  ///@param nResumeType ¿¿¿¿¿¿¿  
  ///        THOST_TERT_RESTART:¿¿¿¿¿¿¿¿¿
  ///        THOST_TERT_RESUME:¿¿¿¿¿¿¿¿
  ///        THOST_TERT_QUICK:¿¿¿¿¿¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿Init¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void SubscribePrivateTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;
  
  ///¿¿¿¿¿¿
  ///@param nResumeType ¿¿¿¿¿¿¿  
  ///        THOST_TERT_RESTART:¿¿¿¿¿¿¿¿¿
  ///        THOST_TERT_RESUME:¿¿¿¿¿¿¿¿
  ///        THOST_TERT_QUICK:¿¿¿¿¿¿¿¿¿¿¿¿
  ///@remark ¿¿¿¿¿Init¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual void SubscribePublicTopic(THOST_TE_RESUME_TYPE nResumeType) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqAuthenticate(CThostFtdcReqAuthenticateField *pReqAuthenticateField, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqUserLogin(CThostFtdcReqUserLoginField *pReqUserLoginField, int nRequestID) = 0;
  

  ///¿¿¿¿
  virtual int ReqUserLogout(CThostFtdcUserLogoutField *pUserLogout, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqOrderInsert(CThostFtdcInputOrderField *pInputOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿
  virtual int ReqSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryOrder(CThostFtdcQryOrderField *pQryOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryTrade(CThostFtdcQryTradeField *pQryTrade, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField *pQryInvestorPosition, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryTradingAccount(CThostFtdcQryTradingAccountField *pQryTradingAccount, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqQryInvestor(CThostFtdcQryInvestorField *pQryInvestor, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryTradingCode(CThostFtdcQryTradingCodeField *pQryTradingCode, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField *pQryInstrumentMarginRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField *pQryInstrumentCommissionRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqQryExchange(CThostFtdcQryExchangeField *pQryExchange, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryProduct(CThostFtdcQryProductField *pQryProduct, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryInstrument(CThostFtdcQryInstrumentField *pQryInstrument, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField *pQryDepthMarketData, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQrySettlementInfo(CThostFtdcQrySettlementInfoField *pQrySettlementInfo, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryTransferBank(CThostFtdcQryTransferBankField *pQryTransferBank, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField *pQryInvestorPositionDetail, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryNotice(CThostFtdcQryNoticeField *pQryNotice, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQrySettlementInfoConfirm(CThostFtdcQrySettlementInfoConfirmField *pQrySettlementInfoConfirm, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInvestorPositionCombineDetail(CThostFtdcQryInvestorPositionCombineDetailField *pQryInvestorPositionCombineDetail, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryCFMMCTradingAccountKey(CThostFtdcQryCFMMCTradingAccountKeyField *pQryCFMMCTradingAccountKey, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryEWarrantOffset(CThostFtdcQryEWarrantOffsetField *pQryEWarrantOffset, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿/¿¿¿¿¿¿
  virtual int ReqQryInvestorProductGroupMargin(CThostFtdcQryInvestorProductGroupMarginField *pQryInvestorProductGroupMargin, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField *pQryExchangeMarginRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField *pQryExchangeMarginRateAdjust, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryExchangeRate(CThostFtdcQryExchangeRateField *pQryExchangeRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQrySecAgentACIDMap(CThostFtdcQrySecAgentACIDMapField *pQrySecAgentACIDMap, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryProductExchRate(CThostFtdcQryProductExchRateField *pQryProductExchRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqQryProductGroup(CThostFtdcQryProductGroupField *pQryProductGroup, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryMMInstrumentCommissionRate(CThostFtdcQryMMInstrumentCommissionRateField *pQryMMInstrumentCommissionRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryMMOptionInstrCommRate(CThostFtdcQryMMOptionInstrCommRateField *pQryMMOptionInstrCommRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿
  virtual int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField *pQryInstrumentOrderCommRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField *pQryOptionInstrTradeCost, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField *pQryOptionInstrCommRate, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryExecOrder(CThostFtdcQryExecOrderField *pQryExecOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryForQuote(CThostFtdcQryForQuoteField *pQryForQuote, int nRequestID) = 0;

  ///¿¿¿¿¿¿
  virtual int ReqQryQuote(CThostFtdcQryQuoteField *pQryQuote, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryCombInstrumentGuard(CThostFtdcQryCombInstrumentGuardField *pQryCombInstrumentGuard, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryCombAction(CThostFtdcQryCombActionField *pQryCombAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryTransferSerial(CThostFtdcQryTransferSerialField *pQryTransferSerial, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryAccountregister(CThostFtdcQryAccountregisterField *pQryAccountregister, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryContractBank(CThostFtdcQryContractBankField *pQryContractBank, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿
  virtual int ReqQryParkedOrder(CThostFtdcQryParkedOrderField *pQryParkedOrder, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryParkedOrderAction(CThostFtdcQryParkedOrderActionField *pQryParkedOrderAction, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿
  virtual int ReqQryTradingNotice(CThostFtdcQryTradingNoticeField *pQryTradingNotice, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryBrokerTradingParams(CThostFtdcQryBrokerTradingParamsField *pQryBrokerTradingParams, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQryBrokerTradingAlgos(CThostFtdcQryBrokerTradingAlgosField *pQryBrokerTradingAlgos, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, int nRequestID) = 0;

  ///¿¿¿¿¿¿¿¿¿¿¿¿
  virtual int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, int nRequestID) = 0;
protected:
  ~CThostFtdcTraderApi(){};
};

#endif
