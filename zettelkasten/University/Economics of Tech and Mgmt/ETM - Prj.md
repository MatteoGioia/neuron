# Project 

The context of this project is the creation of an artificial startup in order to sell a certain program to customers. The project will be broken down in 3 phases:
1. infrastructure setup and publicity
2. selling model for the app, max 200 customers
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

The goal of this phase is determining the right price for the product ensuring the chosen solution maximizes profit. In general, software can be either sold as a service (SaaS) or as a one time purchase. Both solutions offer advantages and disadvanatages. In the first case, the product is sold as a service that is paid monthly. Differently from a one time purchase, it ensures that:
- the customer receives always the latest version of the software
- the customer receives some kind of assistance

In the second case, the customer only receives the current software version and limited assistance (potentially none). This lowers the overall cost for both customer and software seller.

The following graphs show how the price varies w.r.t. to the number of licenses sold. It is assumed that the wanted ROI for the project is 200%, so the target profit would be around 4000 euros (since we chose the "hosted route"), and that the initial investment is already paid for (i.e. we don't find money to pay the hosting service at the end of each month). The plot show a simple equation, $T = xy - V$ where $T$ is the target net operative income, $xy$ are the number of units sold at a certain price and $V$ is the variable price.
For instance, we can see that for the one time buy solution we would need to sell exactly 50 units of product fixing the price at 120 euros each to get to the desired ROI, 100 at 60 and 200 at 30 and so on. It is important to keep in mind that over 200 customers we will probably need to upgrade our machines, so the overall price will increase and all the calculations will have to be done again.

![](../../../static/ETM/fixed_price.png)

Things change if we instead examine the SaaS solution. In this case we consider the monthly profit and expenses (split over 12 months), since we know the customer is going to pay each month to use the service. This, in theory, allows us to lower the price but earn the same amount of money in the end.

![](../../../static/ETM/variable_price.png)

 However, it's hard to determine the right price for our product given its elasticity (we would need to find the right price w.r.t to our competitors). Furthermore, it is even harder to predict the fluctuations in the monthly subscriptions (e.g. a customer could decide to not purchase a license every month). This is both the "strength" and "weakness" of the SaaS solution, and that is why most companies try to build customer loyalty. 
  
  We'll then consider a simpler case of CVP where the price is fixed at 50/25/10 euros and we use the one time pay solution, assuming we have a certain number of customers willing to pay at the end of a certain period (e.g. 3/6 months)
 
 ![](../../../static/ETM/cvp_fixed.png)
 
 We can see that as the price decreases, the nr. of units sold rapidly approaches our maximum number of customers (200). The reason why the variable price is expressed as a whole (and not as a function of the number of units) is that we pay the full price for the entire 5 servers, even if we don't use them. In this regard, there are different solutions (like AWS) that could be used, as they use a "pay-as-you-use" model (you pay what you use).

## Phase 3 (multi criteria analysis and indicators)