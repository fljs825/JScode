void ku_drs_proto_fast(const char* filename = "hani_daq.dat", const unsigned int Nevent = 100000, const unsigned short int dly = 3000, const bool softTrg = false)
{
  gROOT->Reset();

  // set parameter here
  int sid = 1;  	                // KU_DRS_PROTO sid
//  int dly = 3000;                         // trigger input delay, 0 ~ 10000 ns in step of 1 ns
//  char filename[256];                   // data file name
//  sprintf(filename, "run00119.dat");     // set it here
  //sprintf(filename, "coinc.dat");     // set it here
//  int Nevent = 100000;                    // number of event to be taken

  // loading library
  R__LOAD_LIBRARY(libNoticeKU_DRS_PROTOROOT.so);

  // define KU_DRS_PROTO class
  NKKU_DRS_PROTO *drs = new NKKU_DRS_PROTO;

  // local variables for data acquisition
  int ch;
  int evt;
  FILE *fp;
  int buf_cnt;
  char data[32768];
  int i;
  float px;
  int adc[5];
  int value;
  int stop_addr;
  int stop_ch;

  // open drs
  drs->KU_DRS_PROTOopen(sid);

  drs->KU_DRS_PROTOwrite_CALMODE(sid, 0);

  // write setting registers and readback them
  drs->KU_DRS_PROTOwrite_TRIG_DLY(sid, dly);
  printf("trigger delay = %d\n", drs->KU_DRS_PROTOread_TRIG_DLY(sid));
  
  evt = 0;

  // open data file
  fp = fopen(filename, "wb");

  // reset drs
  drs->KU_DRS_PROTOreset(sid);

  // start daq
  drs->KU_DRS_PROTOstart(sid);
  printf("drs run status = %d\n", drs->KU_DRS_PROTOread_RUN(sid));

  while(evt < Nevent) {
    // wait for buffer filled
    buf_cnt = 0;
    while (!buf_cnt) {
      // use this when software trigger is necessary
      if ( softTrg ) drs->KU_DRS_PROTOsend_TRIG(sid);

      buf_cnt = drs->KU_DRS_PROTOread_DATASIZE(sid);

    }


    // read data, if fast readout is necessary, put buf_cnt instead of 1
    // buf_cnt can be up to 2, so please increas data array size in this case
    // and evt = evt + buf_cnt
    drs->KU_DRS_PROTOread_DATA(sid, 1, data);  
    evt = evt + 1;
    if ( evt % 1000 == 0 ) printf("%d-th trigger accepted\n", evt);
    //if ( evt % 10 == 0 ) printf("%d-th trigger accepted\n", evt);

    // write data to file
    fwrite(data, 1, 32768, fp);
          
    //printf("%d / %d events are taken\n", evt, Nevent);
  }

  //stop DRS
  drs->KU_DRS_PROTOstop(sid);
  printf("drs run status = %d\n", drs->KU_DRS_PROTOread_RUN(sid));

  // close file
  fclose(fp);  

  // close drs
  drs->KU_DRS_PROTOclose(sid);
}


