`timescale 1ns / 1ps
`include "define.vh"

module data_mem(clk,reg_we,alucode,we,r_addr,w_addr,r_data,w_data,is_store);//,uart_IN_data,uart_we,uart_tx,uart_OUT_data,hc_OUT_data);
    input clk,reg_we;
    input [31:0] r_addr,w_addr;
    input [31:0]w_data;
    output reg [31:0]r_data;
// input [5:0]alucode;
    input[5:0]alucode;
    input [3:0]we;
    input is_store;
    reg [31:0] mem[0:32767];
   // initial $readmemb("code.hex",mem);



    


/*分散RAMにしているのはそれでないと、*/
 //initial $readmem[r_addr>>2]b 
always @(negedge clk)begin
    case(alucode)
     `ALU_LB:begin
      if(r_addr[1:0]==0)begin

          r_data={{24{mem[r_addr>>2][7]}},mem[r_addr>>2][7:0]};
        
      end else if(r_addr[1:0]==1)begin
           r_data={{24{mem[r_addr>>2][15]}},mem[r_addr>>2][15:8]};
       
      end else if(r_addr[1:0]==2)begin
        r_data={{24{mem[r_addr>>2][23]}},mem[r_addr>>2][23:16]};
      end else begin
       r_data={{24{mem[r_addr>>2][31]}},mem[r_addr>>2][31:24]};
      end
      
  end
  `ALU_LBU:begin
    if(r_addr[1:0]==0)begin
        r_data={24'd0,mem[r_addr>>2][7:0]};
      end else if(r_addr[1:0]==1)begin
        r_data={24'd0,mem[r_addr>>2][15:8]};
      end else if(r_addr[1:0]==2)begin
          r_data={24'd0,mem[r_addr>>2][23:16]};
      end else begin
         r_data={24'd0,mem[r_addr>>2][31:24]};
      end
  end
  `ALU_LH:begin
     if(r_addr[1:0]==2'd0)begin
        r_data={{16{mem[r_addr>>2][15]}},mem[r_addr>>2][15:0]};
       // r_data={{16{mem[r_addr>>2][23]}},mem[r_addr>>2][23:16],mem[r_addr>>2][31:24]};
      end else if(r_addr[1:0]==2'd1)begin
         r_data={{16{mem[r_addr>>2][23]}},mem[r_addr>>2][23:8]};
       // r_data={{16{mem[r_addr>>2][15]}},mem[r_addr>>2][15:8],mem[r_addr>>2][23:16]};
      end else if(r_addr[1:0]==2'd2)begin
          r_data={{16{mem[r_addr>>2][31]}},mem[r_addr>>2][31:16]};
         // r_data={{16{mem[r_addr>>2][7]}},mem[r_addr>>2][7:0],mem[r_addr>>2][15:8]};
      end
  end
  `ALU_LHU:begin
     if(r_addr[1:0]==0)begin
        r_data={16'd0,mem[r_addr>>2][15:0]};
       // r_data={{16{mem[r_addr>>2][15]}},mem[r_addr>>2][15:0]};
       //r_data={16'd0,mem[r_addr>>2][23:16],mem[r_addr>>2][31:24]};
      end else if(r_addr[1:0]==1)begin
      //  r_data={16'd0,mem[r_addr>>2][15:8],mem[r_addr>>2][23:16]};
      r_data={16'd0,mem[r_addr>>2][23:8]};
      end else if(r_addr[1:0]==2)begin
         r_data={16'd0,mem[r_addr>>2][31:16]};
         // r_data={16'd0,mem[r_addr>>2][7:0],mem[r_addr>>2][15:8]};
      end
  end
  `ALU_LW:begin
//   case(r_addr)
//   `HARDWARE_COUNTER_ADDR:begin
//     r_data=hc_OUT_data;
//   end
//    default :r_data=mem[r_addr>>2];
//    endcase
r_data=mem[r_addr>>2];
  end
  default://r_data=32'hffffffff;
    r_data=mem[r_addr>>2];

    endcase

 
    // if(we[1:0]==0)begin
    //   mem[w_addr>>2][7:0]=w_data[7:0];
    
    //   end else if(we[1:0]==1)begin
    //     mem[w_addr>>2][15:8]=w_data[15:8];
       
    //   end else if(we[1:0]==2)begin
    //     mem[w_addr>>2][23:16]=w_data[23:16];
    //      else if(we[1:0]==3)begin
    //        mem[w_addr>>2][31:24]=w_data[31:24];
    //      end
    //   end
    case (w_addr[1:0])
    0 : begin 
        if(we[0]) mem[w_addr>>2][7:0]=w_data[7:0];
        if(we[1]) mem[w_addr>>2][15:8]=w_data[15:8];
        if(we[2]) mem[w_addr>>2][23:16]=w_data[23:16];
        if(we[3]) mem[w_addr>>2][31:24]=w_data[31:24];
    end
     1 : begin
        if(we[0]) mem[w_addr>>2][15:8]=w_data[7:0];
        if(we[1]) mem[w_addr>>2][23:16]=w_data[15:8];
        if(we[2]) mem[w_addr>>2][31:24]=w_data[23:16];
    end
     2 : begin 
        //if(we[0]) mem[w_addr>>2][7:0]=w_data[7:0];
        //if(we[0]) mem[w_addr>>2][15:8]=w_data[15:8];
        if(we[0]) mem[w_addr>>2][23:16]=w_data[7:0];
        if(we[1]) mem[w_addr>>2][31:24]=w_data[15:8];
    end
     3 : begin
        // if(we[0]) mem[w_addr>>2][15:8]=w_data[7:0];
        // if(we[1]) mem[w_addr>>2][23:16]=w_data[15:8];
        if(we[0]) mem[w_addr>>2][31:24]=w_data[7:0];
    end
    
endcase






   //   if(reg_we) mem[w_addr>>2] =w_data;
      
    end




//    assign uart_IN_data=w_data[7:0];
//    assign uart_we=((w_addr==`UART_ADDR)&&(is_store==`ENABLE))?1'b1:1'b0;
//    assign uart_tx=uart_OUT_data;
endmodule