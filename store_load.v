`timescale 1ns / 1ps
`include "define.vh"


module store_load(alucode,we);
// input wire[31:0]rs1,imm;
// input wire[31:0]  rrs;
// input wire[7:0] store_load_addr;
// output reg[31:0]store_load_result;
input [5:0]alucode;
output reg[3:0] we;

always @(*)begin

  case(alucode)
  `ALU_SB:begin
    we[0]=1;
    we[1]=0;
    we[2]=0;
    we[3]=0;

  end
  `ALU_SH:begin
    we[0]=1;
    we[1]=1;
    we[2]=0;
    we[3]=0;
  end
  `ALU_SW:begin 
    we[0]=1;
    we[1]=1;
    we[2]=1;
    we[3]=1;
  end
  default:begin
   we[0]=0;
    we[1]=0;
    we[2]=0;
    we[3]=0;
    end
  endcase
  end




endmodule