//-*- Mode: C++ -*-
// $Id$

#ifndef ALIRAWREADERHLT_H
#define ALIRAWREADERHLT_H
//* This file is property of and copyright by the ALICE HLT Project        * 
//* ALICE Experiment at CERN, All rights reserved.                         *
//* See cxx source for full Copyright notice                               *

/** @file   AliRawReaderHLT.h
    @author Matthias Richter
    @date   
    @brief  AliRawReader implementation which replaces original input of
            detectors with the appropriate HLT output.                    */

// see below for class documentation
// or
// refer to README to build package
// or
// visit http://web.ift.uib.no/~kjeks/doc/alice-hlt

#include "AliHLTDataTypes.h"
#include "AliRawReader.h"      // RAW, base class
#include "AliHLTReconstructorBase.h"
#include "TString.h"
#include <vector>

class AliHLTOUT;
class AliHLTOUTHandler;

/**
 * @class AliRawReaderHLT
 * Handler of HLTOUT data for AliRawReader input.
 */
class AliRawReaderHLT : public AliRawReader, public AliHLTReconstructorBase {
 public:
  /** constructor */
  AliRawReaderHLT(AliRawReader* pParentReader, const char* options=NULL);
  /** destructor */
  virtual ~AliRawReaderHLT();

  // interface methods of AliRawReader
  void     Select(Int_t detectorID, 
		  Int_t minDDLID = -1, Int_t maxDDLID = -1);
//   void     Select(const char *detectorName, 
// 		  Int_t minDDLID = -1, Int_t maxDDLID = -1);

  using AliRawReader::Select;

  void     SelectEquipment(Int_t equipmentType, 
			   Int_t minEquipmentId = -1, 
			   Int_t maxEquipmentId = -1);
  void     SkipInvalid(Bool_t skip = kTRUE);
  void     SelectEvents(Int_t type);

  UInt_t   GetType() const;
  UInt_t   GetRunNumber() const;
  const UInt_t* GetEventId() const;
  const UInt_t* GetTriggerPattern() const;
  const UInt_t* GetDetectorPattern() const;
  const UInt_t* GetAttributes() const;
  const UInt_t* GetSubEventAttributes() const;
  UInt_t   GetLDCId() const;
  UInt_t   GetGDCId() const;
  UInt_t   GetTimestamp() const;

  const UInt_t* GetEquipmentAttributes() const;
  Int_t    GetEquipmentElementSize() const;
  Int_t    GetEquipmentHeaderSize() const;

  Int_t    GetEquipmentSize() const;
  Int_t    GetEquipmentType() const;
  Int_t    GetEquipmentId() const;
  Bool_t   ReadHeader();
  Bool_t   ReadNextData(UChar_t*& data);
  Bool_t   ReadNextInt(UInt_t& data);
  Bool_t   ReadNextShort(UShort_t& data);
  Bool_t   ReadNextChar(UChar_t& data);
  Bool_t   ReadNext(UChar_t* data, Int_t size);

  Bool_t   Reset();

  Bool_t   NextEvent();
  Bool_t   RewindEvents();

 protected:

 private:
  /** standard constructor prohibited */
  AliRawReaderHLT();
  /** copy constructor prohibited */
  AliRawReaderHLT(const AliRawReaderHLT&);
  /** assignment operator prohibited */
  AliRawReaderHLT& operator=(const AliRawReaderHLT&);

  /**
   * Scan the options.
   * Set the ids for the specified detectors in the detector
   * list. Currently, no other options are available.
   */
  int ScanOptions(const char* options);

  /**
   * Read the next data block from the HLT stream
   */
  Bool_t ReadNextHLTData();

  /**
   * Check if a ddlid is part of the ones which are selected for
   * input replacement.
   */
  Bool_t IsHLTInput(int ddlid);

  /**
   * Check if redirection is enabled for at least one detector in the
   * selected range.
   * Set the fbHaveHLTData variable
   * @return true if data has to be read from the HLT stream.
   */
  Bool_t EvaluateSelection();

  /**
   * Release the current HLT data.
   * Releases the current buffer of either the active HLTOUT data
   * block handler or the HLTOUT instance. The latter implies a
   * reset of the reader concerning the HLT data blocks.
   * @param bReleaseHLTOUT   release HLTOUT instance if \em true
   *                         only current data buffer if \em false
   * @return neg. error code if failed
   */
  int ReleaseHLTData(bool bReleaseHLTOUT=true);

  /** the rawreader */
  AliRawReader* fpParentReader; //!transient

  /** options */
  TString fOptions; //!transient

  /** system options = options w/o detector strings */
  TString fSystemOptions; //!transient

  /** current data set, either extracted from the HLT stream or parent raw reader */
  const AliHLTUInt8_t* fpData; // !transient

  /** size of the current data set */
  int fDataSize; // !transient

  /** current stream offset in the data set */
  int fOffset; // !transient

  /** current stream position for the ReadNextData function */
  int fPosition; // !transient

  /** equipment id of the current data set, >0 indicates data set from HLT stream */
  int fEquipmentId; // !transient

  /** indicates the availibility of data from the HLT stream */
  bool fbHaveHLTData; // !transient

  /** list of detectors for which data will be taken from HLT stream */
  vector<int> fDetectors; // !transient

  /** instance of the HLTOUT handler */
  AliHLTOUT* fpHLTOUT; // !transient

  /** instance of the data handler providing the current data buffer */
  AliHLTOUTHandler* fpDataHandler; // !transient

  ClassDef(AliRawReaderHLT, 3)
};

#define ALIHLTREC_LIBRARY                   "libHLTrec.so"
#define ALIHLTREC_LIBRARY_VERSION           0
#define ALIRAWREADERHLT_CREATE_INSTANCE     "AliRawReaderHLTCreateInstance"

#ifdef __cplusplus
extern "C" {
#endif
  typedef AliRawReader* (*AliRawReaderHLTCreateInstance_t)(AliRawReader* pParentReader, const char* options);

  /**
   * Create an instance of the AliRawReader class
   */
  AliRawReader* AliRawReaderHLTCreateInstance(AliRawReader* pParentReader, const char* options);
#ifdef __cplusplus
}
#endif
#endif
