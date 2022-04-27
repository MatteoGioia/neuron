# Project 

The context of this project is the creation of an artificial startup in order to sell a certain program to customers. The project will be broken down in 3 phases:
1. infrastructure setup and publicity
2. selling model for the app
3. indicators

## Phase 1 (infrastructure setup)

 In this phase, it is necessary to set up a certain number of machines in order to run the software. There are 3 possibile alternatives identified:
 - brand new: all the components and infrastructure are bought brand new
 - used: the components are bought on a second hand market (e.g. ebay, subito, etc)
 - rented on the cloud: the bare metal is rented from a cloud provider 
 
Setup (of the software) price is the same for each alternative. Furthermore, in the case of used/new, no economy of scale applies since the nr. of machine is really small. \
To compute hrly pay for the assistance: https://www.fattureincloud.it/guida-freelance/tariffe-freelance-quanto-farsi-pagare/

- Price breakdown for **brand new**
   - price: 1725 euro
   - specs:
     - xeon e 2176g
     - 64gb ddr4 @2666
     - 2 x 8 tb sata 
   - connection price:
    - ILIAD 15.99 mo with fiber?
   - mantainance price (variable labour):
      - technician pay (hourly)
      - setup

- Price breakdown for **used **:
  - price 920 + 230 shipping + 200 hdd
  - specs: see screenshot
  - connection price: same as brand new
  - manteinance: 30 days included 

- Price breakdown for **OVH cloud (final choice)**: 
  - name: advance-1
  - type: bare metal
  - specs:
    - xeon e2386g (6/12)
    - 32 gb ddr4 3200mhz
    - 2 ssd nvme 512gb (1tb)
    - 1 gbit banda 
    - canada
  - final pric in euro: 
    - senza impegno: 89.99 mo. + 89.99 inst
    - 6 mesi: 89.99 mo
    - 12 mesi: 85.49 mo
    - 24 mesi: 80.99 mo

- **Discarded option 3.1** Scaleway:
  - name: EM-B111X-SATA
  - type: bare metal
  - specs:
    - 2x intel xeon e5 2620 (6/12)
    - 192gb ram ECC
    - 2 x 8tb
    - 1 gbit band
  - final price in euro:
    - 0.25 hr/ 89.99 mo

- **Discarded option 3.2** Hetzener:
  - name: PX62
  - type: bare metal
  - specs:
    - xeon e-2176g (6/12)
    - 64gb ram ECC ddr4
    - 2 x 8tb
    - ?? band
  - final price in euro:
    - 88.06 mo. + 94 setup

### Conclusions of phase 1

The hosted route is the most convenient. When we consider the price for maintenance and connection of option 1 and 2, they quickly become less profitable as shown in the following graph. The options become even less profitable if we consider a situation in which we have to pay for electricity (for what regards storage, a spare room in an existing apartment can be used, otherwise the price levitates even more). \
The main advantage of opt. 1 and 2 over 3 is the potential salvage value. When the project is over, the hardware could be sold again in order to re-gain part of the money invested. 

![](../../../static/ETM/phase1_table_img.png)

## Phase 2 (payment)

The goal of this phase is determining the right price for the product and the most profitable solution.

## Phase 3 (indicators - cash flow simulation?)