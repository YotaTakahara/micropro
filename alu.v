`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/12/01 23:44:28
// Design Name: 
// Module Name: alu
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

`include "define.vh"
module alu(
    input wire[5:0] alucode,
    input wire[31:0] op1,
    input wire [31:0] op2,
    output reg [31:0]alu_result,
    output reg br_taken


    );
    wire[5:0]shift=op2[5:0];
    always @(*)begin
      case(alucode)
      `ALU_ADD:begin
         alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_SUB:begin
          alu_result=op1-op2;
        br_taken=`DISABLE;
      end
      `ALU_SLT:begin
          //if($signed({1'b0,op1})<$signed({1'b0,op2}) )begin    
         alu_result=($signed({op1})<$signed({op2}))?1:0;
        br_taken=`DISABLE;
      end
      `ALU_SLTU:begin
          alu_result=(op1<op2)?1:0;
        br_taken=`DISABLE;
      end

      `ALU_XOR:begin
          alu_result=op1^op2;
        br_taken=`DISABLE;
      end
      `ALU_OR:begin
          alu_result=op1|op2;
        br_taken=`DISABLE;
      end
      `ALU_AND:begin
          alu_result=op1&op2;
        br_taken=`DISABLE;
      end

      `ALU_SLL:begin
        alu_result=(op1<<shift);
        br_taken=`DISABLE;
      end
      `ALU_SRL:begin
        alu_result=op1>>shift;
        br_taken=`DISABLE;
      end
      `ALU_SRA:begin
        alu_result=$signed({op1})>>>$signed({shift});
        br_taken=`DISABLE;
      end

      `ALU_JAL:begin
        alu_result=op2+32'd4;
        br_taken=`ENABLE;
      end
      `ALU_JALR:begin
        alu_result=op2+32'd4;
        br_taken=`ENABLE;
      end
      `ALU_BEQ:begin
        alu_result=32'd0;
        br_taken=(op1==op2)?`ENABLE:`DISABLE;
       
      end
     
      `ALU_BNE:begin
        alu_result=32'd0;
         br_taken=(op1!=op2)?`ENABLE:`DISABLE;
      end
      `ALU_BLT:begin
        alu_result=32'd0;
        br_taken=($signed({op1})<$signed({op2}))?`ENABLE:`DISABLE;
      end
     
      `ALU_BLTU:begin
         alu_result=32'd0;
        br_taken=(op1<op2)?`ENABLE:`DISABLE;
      end
      `ALU_BGE:begin
        alu_result=32'd0;
        br_taken=($signed({op2})<=$signed({op1}))?`ENABLE:`DISABLE;
      end

     
      
      `ALU_BGEU: begin
        alu_result=32'd0;
        br_taken=(op2<=op1)?`ENABLE:`DISABLE;
      end
     

      `ALU_LB:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_LH:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_LW:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_LBU:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_LHU:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_SB:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_SH:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end
      `ALU_SW:begin
        alu_result=op1+op2;
        br_taken=`DISABLE;
      end

      `ALU_LUI:begin
        alu_result=op2;
        br_taken=`DISABLE;
      end


      default:begin
          alu_result=32'b0;
          br_taken=`DISABLE;
      end
      endcase
    end
endmodule
