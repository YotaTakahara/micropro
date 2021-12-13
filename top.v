`timescale 1ns / 1ps
`include "define.vh"

module top(
     sysclk,
     cpu_resetn
  ,uart_tx
);

input sysclk;
input cpu_resetn;
//wire  [7:0] r_addr;
//wire [31:0]r_data;
wire reg_we;
reg [31:0]pc;
wire[31:0] ir;
//wire [4:0]rs1_addr,rs2_addr,w_addr;
wire [4:0] srcreg1_num,srcreg2_num;
wire[31:0]alu_result;
wire[4:0] dstreg_num;
wire[31:0] imm;
wire[1:0]aluop1_type,aluop2_type;
wire[31:0]rs1_data,rs2_data,w_data;
wire [5:0]alucode;
wire[3:0]we;
wire[6:0]opcode;
wire[31:0]w_data_memo;
wire [31:0]data_memory;
wire is_halt,is_store,is_load;



//wire[31:0]pc;
wire[31:0]nextPc;
wire br_taken;
wire [31:0]op1,op2;

wire [7:0] uart_IN_data;
wire uart_we;
wire uart_OUT_data;
output wire uart_tx;
wire [31:0]hc_OUT_data;
wire [31:0] new_line;


assign uart_IN_data=w_data_memo[7:0];
assign uart_we=((alu_result==`UART_ADDR)&&(is_store==`ENABLE))?1'b1:1'b0;
assign uart_tx=uart_OUT_data;

assign  new_line =  ((alucode == `ALU_LW) && (alu_result == `HARDWARE_COUNTER_ADDR)) ? hc_OUT_data : data_memory;


always @(posedge sysclk or  posedge cpu_resetn)begin
     if(cpu_resetn)pc<=32'h8000;
else         pc<=nextPc;
end





instruction instuction1(.clk(sysclk),.pc(nextPc),.r_data(ir));

decoder decoder1(.ir(ir),.srcreg1_num(srcreg1_num),.srcreg2_num(srcreg2_num),
          .dstreg_num(dstreg_num),.imm(imm),.alucode(alucode),.aluop1_type(aluop1_type),
          .aluop2_type(aluop2_type),.reg_we(reg_we),.is_load(is_load),
          .is_store(is_store),.is_halt(is_halt),.op(opcode));
reg_file reg_file1( .clk(sysclk),.reg_we(reg_we),.rs1_addr(srcreg1_num),
          .rs2_addr(srcreg2_num),.w_addr(dstreg_num),
          .rs1_data(rs1_data),.rs2_data(rs2_data),.w_data(w_data)
  );
  

multiplexer multiplexer1(.clk(sysclk),.imm(imm),
          .aluop1_type(aluop1_type),.aluop2_type(aluop2_type),.reg_we(reg_we),
          .rs1_data(rs1_data),.rs2_data(rs2_data),.op1(op1),.op2(op2),.pc(pc));
alu alu1(.alucode(alucode),.op1(op1),.op2(op2),
          .alu_result(alu_result),.br_taken(br_taken));

store_load store_load1(.alucode(alucode),.we(we));
data_mem data_mem1(.clk(sysclk),.reg_we(reg_we),.alucode(alucode),
     
          .we(we),.r_addr(alu_result),.w_addr(alu_result),.r_data(data_memory),.w_data(w_data_memo),.is_store(is_store));
          //,.uart_IN_data(uart_IN_data),.uart_we(uart_we),.uart_OUT_data(uart_OUT_data),.uart_tx(uart_tx),.hc_OUT_data(hc_OUT_data));
multiplxer2 multiplxer21(.reg_we(reg_we),.is_load(is_load),.is_store(is_store),
          .is_halt(is_halt),.rs2_data(rs2_data),
          .r_data(w_data),.data_memory(new_line),.w_data_memo(w_data_memo),.alu_result(alu_result));

npc npc1(.br_taken(br_taken),.pc(pc),.imm(imm),.nextPc(nextPc));

uart uart0(
     .uart_tx(uart_OUT_data),
     .uart_wr_i(uart_we),
     .uart_dat_i(uart_IN_data),
     .sys_clk_i(sysclk),
     .sys_rstn_i(cpu_resetn)
);
hardware_counter hardware_counter0(
     .CLK_IP(sysclk),
     .RSTN_IP(cpu_resetn),
     .COUNTER_OP(hc_OUT_data)
);

endmodule


