`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2021/11/29 09:44:00
// Design Name: 
// Module Name: decoder
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


module decoder(
    input wire[31:0] ir,     //
    output reg[4:0] srcreg1_num,//
    output reg[4:0] srcreg2_num,//
    output reg[4:0] dstreg_num,//
    output reg[31:0] imm,//
    output reg [5:0] alucode,//
    output reg[1:0] aluop1_type,//
    output reg [1:0] aluop2_type,//
    output reg reg_we,//
    output reg is_load,//
    output reg is_store,//
    output reg is_halt,
    output  wire[6:0]op
 //   output wire [6:0]op;
    

    );
  // wire [6:0]op;
 assign  op=ir[6:0];
   wire [2:0]opcode;
 assign opcode=ir[14:12];
 reg[31:0]temp;
    

    
        
always @(*)begin
    case(op)
    `OPIMM:begin
        srcreg1_num=ir[19:15];
        srcreg2_num=5'b0;
        dstreg_num=ir[11:7];
       
        aluop1_type=`OP_TYPE_REG;
       
        reg_we= `ENABLE;
        is_load=`DISABLE;
        is_store=`DISABLE;
        is_halt=`DISABLE;
        case(opcode)
        3'b000:begin
          alucode=`ALU_ADD; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};
        end      
        3'b010:begin
          
       alucode=`ALU_SLT; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};
        end
        3'b011:begin alucode=`ALU_SLTU; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};end
        3'b100:begin alucode=`ALU_XOR; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};end
        3'b110:begin alucode=`ALU_OR; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};end
        3'b111:begin alucode=`ALU_AND; aluop2_type= `OP_TYPE_IMM; imm={{20{ir[31]}},ir[31:20]};end


        3'b001:begin alucode=`ALU_SLL; aluop2_type= `OP_TYPE_IMM; imm={{27{ir[31]}},ir[24:20]};end
        3'b101:begin
          aluop2_type= `OP_TYPE_IMM; imm={{27{ir[24]}},ir[24:20]};
          case(ir[30])

          0:alucode=`ALU_SRL;
          1:alucode=`ALU_SRA;
           default:;
          
          endcase           

        
        end
        default:;
        endcase
    end
    `OP:begin
      srcreg1_num=ir[19:15];
      srcreg2_num=ir[24:20];
      dstreg_num=ir[11:7];
      imm=32'b0;
      aluop1_type=`OP_TYPE_REG;
      aluop2_type= `OP_TYPE_REG;
      reg_we= `ENABLE;
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE;
      case(opcode)
      3'b000:begin
        case(ir[30])
        1'b0:alucode=`ALU_ADD;
        1'b1:alucode=`ALU_SUB;
        default:;
        endcase
      end
      3'b001:alucode=`ALU_SLL;
      3'b010:alucode=`ALU_SLT;
      3'b011:alucode=`ALU_SLTU;
      3'b100:alucode=`ALU_XOR;
      3'b101:begin
          case(ir[30])
          0:alucode=`ALU_SRL;
          1:alucode=`ALU_SRA;
           default:;
          
          endcase     
      end
      3'b110:alucode=`ALU_OR;
      3'b111:alucode=`ALU_AND;

       default:;
      endcase
    end
    `LUI:begin
      srcreg1_num=5'b0;
      srcreg2_num=5'b0;
      dstreg_num=ir[11:7];
     
      
      imm={ir[31:12],12'd0};
      
      alucode=`ALU_LUI;
       aluop1_type=`OP_TYPE_NONE;
      aluop2_type= `OP_TYPE_IMM;
      reg_we= `ENABLE;
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE;      
    end

    `AUIPC:begin
      srcreg1_num=5'b0;
      srcreg2_num=5'b0;
      dstreg_num=ir[11:7];
       // imm={{20{ir[31]}},ir[31:20]};
       // imm={ir[31:12],{12{0}}};
        imm={ir[31:12],12'd0};
       alucode=`ALU_ADD;
       aluop1_type=`OP_TYPE_IMM;
      aluop2_type= `OP_TYPE_PC;
      reg_we= `ENABLE;
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE; 
    end
    `JAL:begin
     // reg [31:0]tmp;
      imm={{11{ir[31]}},ir[31],ir[19:12],ir[20],ir[30:21],{1'b0}};
      srcreg1_num=5'b0;
      srcreg2_num=5'b0;
      dstreg_num=ir[11:7];
      //imm={{20{ir[31]}},ir[31:20]};
       alucode=`ALU_JAL;
       aluop1_type=`OP_TYPE_NONE;
      aluop2_type= `OP_TYPE_PC;
      case(dstreg_num)
      5'b0:reg_we= `DISABLE;
      5'b1:reg_we= `ENABLE;
      default:reg_we= `ENABLE;
      endcase
      
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE; 
    end
    `JALR:begin
      srcreg1_num=ir[19:15];
      srcreg2_num=5'b0;
      dstreg_num=ir[11:7];
      imm={{20{ir[31]}},ir[31:20]};
      alucode=`ALU_JALR;
       aluop1_type=`OP_TYPE_REG;
      aluop2_type= `OP_TYPE_PC;
      case(dstreg_num)
      0:reg_we= `DISABLE;
      1:reg_we= `ENABLE;
       default:;
    endcase
      
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE; 
    end
    `BRANCH:begin
      imm={{19{ir[31]}},ir[31],ir[7],ir[30:25],ir[11:8],{1'b0}};
       srcreg1_num=ir[19:15];
      srcreg2_num=ir[24:20];
      dstreg_num=5'b0;
      aluop1_type=`OP_TYPE_REG;
      aluop2_type= `OP_TYPE_REG;
      reg_we= `DISABLE;
      is_load=`DISABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE;
      case(opcode)
      3'b0: alucode=`ALU_BEQ;
      3'b001: alucode=`ALU_BNE;
      3'b100: alucode=`ALU_BLT;
      3'b101: alucode=`ALU_BGE;
      3'b110: alucode=`ALU_BLTU;
      3'b111: alucode=`ALU_BGEU;
       default:;
      endcase
     //imm={20{tmp[31]},tmp[31:25],tmp[11:7]};

    end
    `STORE:begin
      imm={{20{ir[31]}},ir[31:25],ir[11:7]};
      srcreg1_num=ir[19:15];
      srcreg2_num=ir[24:20];
      dstreg_num=5'b0;
      aluop1_type=`OP_TYPE_REG;
      aluop2_type= `OP_TYPE_IMM;
      reg_we= `DISABLE;
      is_load=`DISABLE;
      is_store=`ENABLE;
      is_halt=`DISABLE;
      case(opcode)
      3'b000:alucode=`ALU_SB;
      3'b001:alucode=`ALU_SH;
      3'b010:alucode=`ALU_SW;
       default:;
      endcase
    //  imm={20{tmp[31]},tmp[31:25],tmp[4:0]};
    end
    `LOAD:begin
       
      srcreg1_num=ir[19:15];
      srcreg2_num=5'b0;
      dstreg_num=ir[11:7];
      imm={{20{ir[31]}},ir[31:20]};
      aluop1_type=`OP_TYPE_REG;
      aluop2_type= `OP_TYPE_IMM;
      reg_we= `ENABLE;
      is_load=`ENABLE;
      is_store=`DISABLE;
      is_halt=`DISABLE;
      case(opcode)
      3'b000:alucode=`ALU_LB;
      3'b001:alucode=`ALU_LH;
      3'b010:alucode=`ALU_LW;
      3'b100:alucode=`ALU_LBU;
      3'b101:alucode=`ALU_LHU;
       default:;
      endcase
    end
     default:;
    endcase
end

    
    
    
endmodule
